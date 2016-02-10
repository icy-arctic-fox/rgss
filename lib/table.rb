# NOTE: This file does not provide functionality for RGSS.
# It is used for documentation purposes only.

class Table

  def initialize(xsize, ysize = 1, zsize = 1)
    fail NotImplementedError
  end

  def resize(xsize, ysize = nil, zsize = nil)
    fail NotImplementedError
  end

  def xsize
    fail NotImplementedError
  end

  def ysize
    fail NotImplementedError
  end

  def zsize
    fail NotImplementedError
  end

  def [](x, y = 0, z = 0)
    fail NotImplementedError
  end

  def []=(x, y = 0, z = 0, value = nil)
    fail NotImplementedError
  end

end
