RPG Maker RGSS3
===============

Implementation of the RGSS3 engine that powers RPG Maker VX games.
This gem can be used in different ways.
One way, the gem can be included in utilities outside of RPG Maker.
For example, retrieving, updating, and storing data in RPG Maker project files.
The gem can also be used to run an RPG Maker game from Ruby.
Credit goes to Enterbrain for the original architecture (structure) of the RGSS engine and its classes and modules.

Project Structure
-----------------

This project can be built using two systems - Rake and CMake.
The Rake method is intended more from Ruby developers.
The CMake method is used to produce files that can be substituted in for Enterbrain's RPG Maker binaries.

The following is a description of the directory structure used for this project.

- `ext/` - Ruby native extension for RGSS. The actual code for RGSS is not here. Describes how to build RGSS with CMake.
- `include/` - Header files for C++ implementation of the RGSS engine.
- `lib/` - Ruby scripts. This includes everything in the RPG module and method stubs for the RGSS modules and classes.
  - `rpg/` - RPG module. Contains the classes provided by RPG Maker VX. RGSS doesn't depend on these.
- `spec/` - Test scripts. RSpec is used to test the functionality.
- `src/` - C/C++ code. Native extension code for the gem and Game executable.
  - `rgss/` - C++ implementation of the RGSS engine.
  - `binding/` - C binding. Ties the ruby methods to the C++ implementation.
  - `game/` - Bootstrap program for running RPG Maker VX games.
  - `rb2c/` - Utility for converting a Ruby script into a C file.

Ruby Usage
----------

Add this line to your application's Gemfile:

```ruby
gem 'rpg-maker-rgss3'
```

And then execute:

    $ bundle

Or install it yourself as:

    $ gem install rpg-maker-rgss3
