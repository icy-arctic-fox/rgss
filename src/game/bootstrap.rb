require 'zlib'

SCRIPTS_FILE = 'Data/Scripts.rvdata2'

scripts = File.open(SCRIPTS_FILE, 'rb') do |f|
  Marshal.load(f)
end

scripts.each do |script|
  contents = Zlib.inflate(script[2])
  eval contents, nil, script[1]
end
