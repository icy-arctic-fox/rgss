# NOTE: This file does not provide functionality for RGSS.
# It is used for documentation purposes only.

class Font

  def initialize(name = nil, size = nil)
    fail NotImplementedError
  end

  def self.exist?(name)
    fail NotImplementedError
  end

  attr_accessor :name

  attr_accessor :size

  attr_accessor :bold

  attr_accessor :italic

  attr_accessor :outline

  attr_accessor :shadow

  attr_accessor :color

  attr_accessor :out_color

  class << self

    attr_accessor :default_name

    attr_accessor :default_size

    attr_accessor :default_bold

    attr_accessor :default_italic

    attr_accessor :default_shadow

    attr_accessor :default_outline

    attr_accessor :default_color

    attr_accessor :default_out_color

  end
end
