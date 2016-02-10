# NOTE: This file does not provide functionality for RGSS.
# It is used for documentation purposes only.

class Window

  def initialize(x = nil, y = nil, width = nil, height = nil)
    fail NotImplementedError
  end

  def dispose
    fail NotImplementedError
  end

  def disposed?
    fail NotImplementedError
  end

  def update
    fail NotImplementedError
  end

  def move(x, y, width, height)
    fail NotImplementedError
  end

  def open?
    fail NotImplementedError
  end

  def close?
    fail NotImplementedError
  end

  attr_accessor :windowskin

  attr_accessor :contents

  attr_accessor :cursor_rect

  attr_accessor :viewport

  attr_accessor :active

  attr_accessor :visible

  attr_accessor :arrows_visible

  attr_accessor :pause

  attr_accessor :x

  attr_accessor :y

  attr_accessor :width

  attr_accessor :height

  attr_accessor :z

  attr_accessor :ox

  attr_accessor :oy

  attr_accessor :padding

  attr_accessor :padding_bottom

  attr_accessor :opacity

  attr_accessor :back_opacity

  attr_accessor :contents_opacity

  attr_accessor :openness

  attr_accessor :tone

end
