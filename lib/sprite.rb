# NOTE: This file does not provide functionality for RGSS.
# It is used for documentation purposes only.

class Sprite

  def initialize(viewport = nil)
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

  def width
    fail NotImplementedError
  end

  def height
    fail NotImplementedError
  end

  attr_accessor :bitmap

  attr_accessor :src_rect

  attr_accessor :viewport

  attr_accessor :visible

  attr_accessor :visible

  attr_accessor :x

  attr_accessor :y

  attr_accessor :z

  attr_accessor :ox

  attr_accessor :oy

  attr_accessor :zoom_x

  attr_accessor :zoom_y

  attr_accessor :angle

  attr_accessor :wave_amp

  attr_accessor :wave_length

  attr_accessor :wave_speed

  attr_accessor :wave_phase

  attr_accessor :mirror

  attr_accessor :bush_depth

  attr_accessor :bush_opacity

  attr_accessor :opacity

  attr_accessor :blend_type

  attr_accessor :color

  attr_accessor :tone

end
