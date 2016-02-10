# coding: utf-8
Gem::Specification.new do |spec|
  spec.name        = 'rpg-maker-rgss3'
  spec.version     = '1.02.0'
  spec.authors     = ['Enterbrain', 'Michael Miller']
  spec.email       = ['icy-arctic-fox@gmail.com']
  spec.summary     = 'Implementation of the RPG Maker VX engine - RGSS3.'
  spec.description = %q{Implementation of the RGSS3 engine that powers RPG Maker VX games.
This gem can be used in different ways.
One way, the gem can be included in utilities outside of RPG Maker.
For example, retrieving, updating, and storing data in RPG Maker project files.
The gem can also be used to run an RPG Maker game from Ruby.
Credit goes to Enterbrain for the original architecture (structure) of the RGSS engine and its classes and modules.}
  spec.homepage    = 'https://code.turtleboxgames.com/yggdrasil/rgss'

  spec.files         = `git ls-files -z`.split("\x0")
  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ['lib']

  spec.add_development_dependency 'bundler', '~> 1.7'
  spec.add_development_dependency 'rake', '~> 10.0'
end
