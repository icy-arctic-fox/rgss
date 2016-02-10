# NOTE: This file does not provide functionality for RGSS.
# It is used for documentation purposes only.

module Input

  LEFT = :LEFT

  UP = :UP

  RIGHT = :RIGHT

  DOWN = :DOWN

  A = :A

  B = :B

  C = :C

  X = :X

  Y = :Y

  Z = :Z

  L = :L

  R = :R

  SHIFT = :SHIFT

  CTRL = :CTRL

  ALT = :ALT

  F5 = :F5

  F6 = :F6

  F7 = :F7

  F8 = :F8

  F9 = :F9

  class << self

    def update
      fail NotImplementedError
    end

    def press?(sym)
      fail NotImplementedError
    end

    def trigger?(sym)
      fail NotImplementedError
    end

    def repeat?(sym)
      fail NotImplementedError
    end

    def dir4
      fail NotImplementedError
    end

    def dir8
      fail NotImplementedError
    end

  end
end
