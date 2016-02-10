# NOTE: This file does not provide functionality for RGSS.
# It is used for documentation purposes only.

class Viewport

  def initialize(arg1 = nil, y = nil, width = nil, height = nil)
    fail NotImplementedError
  end

  def dispose
    fail NotImplementedError
  end

  def disposed?
    fail NotImplementedError
  end

  def flash(color, duration)
    fail NotImplementedError
  end

  def update
    fail NotImplementedError
  end

  attr_accessor :rect

  attr_accessor :visible

  attr_accessor :z

  attr_accessor :ox

  attr_accessor :oy

  attr_accessor :color

  attr_accessor :tone

end
