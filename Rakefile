require 'rubygems'
require 'rubygems/package_task'
require 'bundler/gem_tasks'
require 'rake/extensiontask'
require 'rspec/core/rake_task'
require 'yard'

task :default => [:compile, :build]

# :build - Task to create gem.
gem_file = File.expand_path('../rpg-maker-rgss3.gemspec', __FILE__)
gemspec  = Gem::Specification::load(gem_file)
Gem::PackageTask.new(gemspec)

# :compile - Task to compile the native extension.
Rake::ExtensionTask.new('rgss', gemspec) do |r|
  r.lib_dir = 'lib/rgss'
end

# :spec - Task to run unit tests.
RSpec::Core::RakeTask.new(:spec)
task :spec => :compile # Need RGSS functionality compiled before testing.
task :test => :spec

# :doc - Task to create documentation.
YARD::Rake::YardocTask.new do |t|
  t.files = %w(lib/**/*.rb - *.md)
end
task :doc => :yard

# :install - Task to build and install the gem.
desc 'Builds and install the gem for sfrgss'
task :install => :build do
  sh "gem install pkg/#{gemspec.name}-#{gemspec.version}.gem"
end
