module RPG
  class Enemy
    class DropItem
      def initialize
        @kind = 0
        @data_id = 1
        @denominator = 1
      end
      attr_accessor :kind
      attr_accessor :data_id
      attr_accessor :denominator
    end
  end
end
