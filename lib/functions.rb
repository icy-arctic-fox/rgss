# Top-level methods provided by RGSS.

def rgss_main(&block)
  fail NotImplementedError
end

def rgss_stop
  fail NotImplementedError
end

def load_data(filename)
  File.open(filename, 'rb') do |f|
    Marshal.load(f)
  end
end

def save_data(obj, filename)
  File.open(filename, 'wb') do |f |
    Marshal.dump(obj, f)
  end
end

def msgbox(arg, *args)
  fail NotImplementedError
end

def msgbox_p(obj, *objs)
  msgbox obj.inspect, "\n", *(objs.flat_map { |obj| [obj, "\n"] }[0...-1])
end
