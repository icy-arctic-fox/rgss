# Top-level methods provided by RGSS.

# @!method rgss_main

# @!method rgss_stop

def load_data(filename)
  File.open(filename, 'rb') do |f|
    Marshal.load(f)
  end
end

def save_data(obj, filename)
  File.open(filename, 'wb') do |f |
    Marshal.dump(obj, f)
  end
  nil
end

# @!method msgbox(arg, *args)

def msgbox_p(obj, *objs)
  msgbox obj.inspect, "\n", *(objs.flat_map { |obj| [obj, "\n"] }[0...-1])
end
