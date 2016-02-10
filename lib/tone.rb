# NOTE: This file does not provide functionality for RGSS.
# It is used for documentation purposes only.

class Tone

  def initialize(red = 0, green = 0, blue = 0, gray = 0)
    fail NotImplementedError
  end

  def set(arg1, green = nil, blue = nil, gray = nil)
    fail NotImplementedError
  end

  attr_accessor :red

  attr_accessor :green

  attr_accessor :blue

  attr_accessor :gray

end
