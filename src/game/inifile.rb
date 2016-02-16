#encoding: UTF-8

class IniFile
  include Enumerable

  class Error < StandardError; end
  VERSION = '3.0.0'

  def self.load( filename, opts = {} )
    return unless File.file? filename
    new(opts.merge(:filename => filename))
  end

  attr_accessor :filename

  attr_accessor :encoding

  def initialize( opts = {} )
    @comment  = opts.fetch(:comment, ';#')
    @param    = opts.fetch(:parameter, '=')
    @encoding = opts.fetch(:encoding, nil)
    @default  = opts.fetch(:default, 'global')
    @filename = opts.fetch(:filename, nil)
    content   = opts.fetch(:content, nil)

    @ini = Hash.new {|h,k| h[k] = Hash.new}

    if    content.is_a?(Hash) then merge!(content)
    elsif content             then parse(content)
    elsif @filename           then read
    end
  end

  def write( opts = {} )
    filename = opts.fetch(:filename, @filename)
    encoding = opts.fetch(:encoding, @encoding)
    mode = encoding ? "w:#{encoding}" : "w"

    File.open(filename, mode) do |f|
      @ini.each do |section,hash|
        f.puts "[#{section}]"
        hash.each {|param,val| f.puts "#{param} #{@param} #{escape_value val}"}
        f.puts
      end
    end

    self
  end
  alias :save :write

  def read( opts = {} )
    filename = opts.fetch(:filename, @filename)
    encoding = opts.fetch(:encoding, @encoding)
    return unless File.file? filename

    mode = encoding ? "r:#{encoding}" : "r"
    File.open(filename, mode) { |fd| parse fd }
    self
  end
  alias :restore :read

  def to_s
    s = []
    @ini.each do |section,hash|
      s << "[#{section}]"
      hash.each {|param,val| s << "#{param} #{@param} #{escape_value val}"}
      s << ""
    end
    s.join("\n")
  end

  def to_h
    @ini.dup
  end

  def merge( other )
    self.dup.merge!(other)
  end

  def merge!( other )
    return self if other.nil?

    my_keys = @ini.keys
    other_keys = case other
      when IniFile
        other.instance_variable_get(:@ini).keys
      when Hash
        other.keys
      else
        raise Error, "cannot merge contents from '#{other.class.name}'"
      end

    (my_keys & other_keys).each do |key|
      case other[key]
      when Hash
        @ini[key].merge!(other[key])
      when nil
        nil
      else
        raise Error, "cannot merge section #{key.inspect} - unsupported type: #{other[key].class.name}"
      end
    end

    (other_keys - my_keys).each do |key|
      @ini[key] = case other[key]
        when Hash
          other[key].dup
        when nil
          {}
        else
          raise Error, "cannot merge section #{key.inspect} - unsupported type: #{other[key].class.name}"
        end
    end

    self
  end

  def each
    return unless block_given?
    @ini.each do |section,hash|
      hash.each do |param,val|
        yield section, param, val
      end
    end
    self
  end

  def each_section
    return unless block_given?
    @ini.each_key {|section| yield section}
    self
  end

  def delete_section( section )
    @ini.delete section.to_s
  end

  def []( section )
    return nil if section.nil?
    @ini[section.to_s]
  end

  def []=( section, value )
    @ini[section.to_s] = value
  end

  def match( regex )
    @ini.dup.delete_if { |section, _| section !~ regex }
  end

  def has_section?( section )
    @ini.has_key? section.to_s
  end

  def sections
    @ini.keys
  end

  def freeze
    super
    @ini.each_value {|h| h.freeze}
    @ini.freeze
    self
  end

  def taint
    super
    @ini.each_value {|h| h.taint}
    @ini.taint
    self
  end

  def dup
    other = super
    other.instance_variable_set(:@ini, Hash.new {|h,k| h[k] = Hash.new})
    @ini.each_pair {|s,h| other[s].merge! h}
    other.taint if self.tainted?
    other
  end

  def clone
    other = dup
    other.freeze if self.frozen?
    other
  end

  def eql?( other )
    return true if equal? other
    return false unless other.instance_of? self.class
    @ini == other.instance_variable_get(:@ini)
  end
  alias :== :eql?

  def escape_value( value )
    value = value.to_s.dup
    value.gsub!(%r/\\([0nrt])/, '\\\\\1')
    value.gsub!(%r/\n/, '\n')
    value.gsub!(%r/\r/, '\r')
    value.gsub!(%r/\t/, '\t')
    value.gsub!(%r/\0/, '\0')
    value
  end

  def parse( content )
    parser = Parser.new(@ini, @param, @comment, @default)
    parser.parse(content)
    self
  end

  class Parser

    attr_writer :section
    attr_accessor :property
    attr_accessor :value

    def initialize( hash, param, comment, default )
      @hash = hash
      @default = default

      comment = comment.to_s.empty? ? "\\z" : "\\s*(?:[#{comment}].*)?\\z"

      @section_regexp  = %r/\A\s*\[([^\]]+)\]#{comment}/
      @ignore_regexp   = %r/\A#{comment}/
      @property_regexp = %r/\A(.*?)(?<!\\)#{param}(.*)\z/

      @open_quote      = %r/\A\s*(".*)\z/
      @close_quote     = %r/\A(.*(?<!\\)")#{comment}/
      @full_quote      = %r/\A\s*(".*(?<!\\)")#{comment}/
      @trailing_slash  = %r/\A(.*)(?<!\\)\\#{comment}/
      @normal_value    = %r/\A(.*?)#{comment}/
    end

    def leading_quote?
      value && value =~ %r/\A"/
    end

    def parse_value( string )
      continuation = false

      if leading_quote?
        # check for a closing quote at the end of the string
        if string =~ @close_quote
          value << $1

        else
          value << string
          continuation = true
        end

      else
        case string
        when @full_quote
          self.value = $1

        when @open_quote
          self.value = $1
          continuation = true

        when @trailing_slash
          self.value ?  self.value << $1 : self.value = $1
          continuation = true

        when @normal_value
          self.value ?  self.value << $1 : self.value = $1

        else
          error
        end
      end

      if continuation
        self.value << $/ if leading_quote?
      else
        process_property
      end

      continuation
    end

    def parse( content )
      return unless content

      continuation = false

      @hash.clear
      @line = nil
      self.section = nil

      content.each_line do |line|
        @line = line.chomp

        if continuation
          continuation = parse_value @line
        else
          case @line
          when @ignore_regexp
            nil
          when @section_regexp
            self.section = @hash[$1]
          when @property_regexp
            self.property = $1.strip
            error if property.empty?

            continuation = parse_value $2
          else
            error
          end
        end
      end

      if leading_quote?
        error "Unmatched open quote"
      elsif property && value
        process_property
      elsif value
        error
      end

      nil
    end

    def process_property
      property.strip!
      value.strip!

      self.value = $1 if value =~ %r/\A"(.*)(?<!\\)"\z/m

      section[property] = typecast(value)

      self.property = nil
      self.value = nil
    end

    def section
      @section ||= @hash[@default]
    end

    def error( msg = 'Could not parse line' )
      raise Error, "#{msg}: #{@line.inspect}"
    end

    def typecast( value )
      case value
      when %r/\Atrue\z/i;  true
      when %r/\Afalse\z/i; false
      when %r/\A\s*\z/i;   nil
      else
        Integer(value) rescue \
        Float(value)   rescue \
        unescape_value(value)
      end
    end

    def unescape_value( value )
      value = value.to_s
      value.gsub!(%r/\\[0nrt\\]/) { |char|
        case char
        when '\0';   "\0"
        when '\n';   "\n"
        when '\r';   "\r"
        when '\t';   "\t"
        when '\\\\'; "\\"
        end
      }
      value
    end
  end

end
