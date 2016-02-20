require 'zlib'

CONFIG_FILE = 'Game.ini'
config = IniFile.load(CONFIG_FILE)
scripts_file = config['Game']['Scripts']

scripts = File.open(scripts_file, 'rb') do |f|
  Marshal.load(f)
end

begin
  scripts.each do |script|
    contents = Zlib.inflate(script[2])
    eval contents, nil, script[1]
  end
rescue Object => ex
  $stderr.puts "#{ex.class}: #{ex.message}"
  ex.backtrace.each do |item|
    $stderr.puts "\tfrom #{item}"
  end
end
