require 'rubygems'
require 'rubygems/package_task'
require 'bundler/gem_tasks'
require 'yard'

task :default => :build

# :build - Task to create gem.
gem_file = File.expand_path('../rpg-maker-rgss3.gemspec', __FILE__)
gemspec  = Gem::Specification::load(gem_file)
Gem::PackageTask.new(gemspec)

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
