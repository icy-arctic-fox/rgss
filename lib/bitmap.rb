# NOTE: This file does not provide functionality for RGSS.
# It is used for documentation purposes only.

class Bitmap

  def initialize(arg1, height)
    fail NotImplementedError
  end

  def dispose
    fail NotImplementedError
  end

  def disposed?
    fail NotImplementedError
  end

  def width
    fail NotImplementedError
  end

  def height
    fail NotImplementedError
  end

  def rect
    fail NotImplementedError
  end

  def blt(x, y, src_bitmap, src_rect, opacity = 255)
    fail NotImplementedError
  end

  def stretch_blt(dest_rect, src_bitmap, src_rect, opacity = 255)
    fail NotImplementedError
  end

  def fill_rect(arg1, arg2,width = nil, height = nil, color = nil)
    fail NotImplementedError
  end

  def gradient_fill_rect(arg1, arg2, arg3, arg4 = nil, arg5 = nil, arg6 = nil)
    fail NotImplementedError
  end

  def clear
    fail NotImplementedError
  end

  def clear_rect(arg1, y = 0, width = nil, height = nil)
    fail NotImplementedError
  end

  def get_pixel(x, y)
    fail NotImplementedError
  end

  def set_pixel(x, y, color)
    fail NotImplementedError
  end

  def hue_change(hue)
    fail NotImplementedError
  end

  def blur
    fail NotImplementedError
  end

  def radial_blur(angle, division)
    fail NotImplementedError
  end

  def draw_text(arg1, arg2, arg3, height = nil, arg5 = nil, arg6 = nil)
    fail NotImplementedError
  end

  def text_size(str)
    fail NotImplementedError
  end

  attr_accessor :font

end
