require 'bundler/gem_tasks'
require 'yard'

task :default => :build
task :doc => :yard

YARD::Rake::YardocTask.new do |t|
  t.files = %w(lib/**/*.rb - *.md)
end
