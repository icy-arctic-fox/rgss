# NOTE: This file does not provide functionality for RGSS.
# It is used for documentation purposes only.

class Plane

  def initialize(viewport = nil)
    fail NotImplementedError
  end

  def dispose
    fail NotImplementedError
  end

  def disposed?
    fail NotImplementedError
  end

  attr_accessor :bitmap

  attr_accessor :viewport

  attr_accessor :visible

  attr_accessor :z

  attr_accessor :ox

  attr_accessor :oy

  attr_accessor :zoom_x

  attr_accessor :zoom_y

  attr_accessor :opacity

  attr_accessor :blend_type

  attr_accessor :color

  attr_accessor :tone

end
