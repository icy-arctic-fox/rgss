module RPG
  class BaseItem
    class Feature
      def initialize(code = 0, data_id = 0, value = 0)
        @code = code
        @data_id = data_id
        @value = value
      end
      attr_accessor :code
      attr_accessor :data_id
      attr_accessor :value
    end
  end
end
