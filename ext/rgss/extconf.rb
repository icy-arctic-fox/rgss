require 'mkmf'
require 'shellwords'

CMAKE_BUILD_TYPE = 'RelWithDebInfo'

EXTENSION = 'rgss'
PWD       = Dir.pwd
CWD       = File.expand_path(File.dirname(__FILE__))
RGSS_DIR  = File.join(CWD, '..', '..')
LIB_DIR   = File.join(RGSS_DIR, 'lib', EXTENSION)
BUILD_DIR = 'build'

def sys(command, *args)
  command_string = [command, *args].map do |part|
    Shellwords.escape part
  end.join(' ')
  puts "%> #{command_string}"
  system(command, *args) || fail("Error: #{command} failed!")
end

# Use system-defined C and C++ compilers, if set.
RbConfig::MAKEFILE_CONFIG['CC']  = ENV['CC']  if ENV['CC']
RbConfig::MAKEFILE_CONFIG['CXX'] = ENV['CXX'] if ENV['CXX']

# Find Make.
unless (MAKE = find_executable('make') ||
  find_executable('gmake') ||
  find_executable('mingw32-make') ||
  find_executable('mingw64-make'))
  abort 'Error: GNU Make is required to build RGSS.'
end

# Find CMake.
unless find_executable('cmake')
  abort 'Error: CMake is required to build RGSS.'
end

# The makefile generated here is fake.
# CMake will generate its own that is used instead.
dir_config(EXTENSION)
create_makefile(EXTENSION)

# Perform the CMake build in <ROOT>/build
Dir.chdir(RGSS_DIR) do
  Dir.mkdir(BUILD_DIR) unless Dir.exist?(BUILD_DIR)
  Dir.chdir(BUILD_DIR) do
    INSTALL_PREFIX = File.join(RGSS_DIR, BUILD_DIR)
    GENERATOR      = MAKE.include?('mingw') ? 'MinGW Makefiles' : 'Unix Makefiles'
    sys('cmake', RGSS_DIR, '-G', GENERATOR, "-DCMAKE_INSTALL_PREFIX=#{INSTALL_PREFIX}", "-DCMAKE_BUILD_TYPE=#{CMAKE_BUILD_TYPE}")
    sys(MAKE, 'install')

    # Installed files are dropped in the current directory.
    # Copy them to the staging area.
    Dir.new('.').grep(/^librgss\./).each do |file|
      # Remove 'lib' prefix
      # and change .dll to .so on Windows.
      dest_file  = file.sub('lib', '').sub('.dll', '.so')
      build_dest = File.join(PWD, dest_file)
      lib_dest   = File.join(LIB_DIR, dest_file)
      puts "cp #{file} #{build_dest}"
      FileUtils.copy(file, build_dest)
      puts "cp #{file} #{lib_dest}"
      FileUtils.copy(file, lib_dest)
    end
  end
end
