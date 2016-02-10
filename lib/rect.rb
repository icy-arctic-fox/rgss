# NOTE: This file does not provide functionality for RGSS.
# It is used for documentation purposes only.

class Rect

  def initialize(x = 0, y = 0, width = 0, height = 0)
    fail NotImplementedError
  end

  def set(arg1, y = nil, width = nil, height = nil)
    fail NotImplementedError
  end

  def empty
    fail NotImplementedError
  end

  attr_accessor :x

  attr_accessor :y

  attr_accessor :width

  attr_accessor :height

end
