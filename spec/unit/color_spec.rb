require_relative '../spec_helper'

RSpec.describe Color do

  describe '#new' do

    context 'with no parameters' do
      let(:color) { Color.new }

      describe '#red' do
        subject { color.red }
        it 'is 0' do
          is_expected.to eq 0.0
        end
      end

      describe '#green' do
        subject { color.green }
        it 'is 0' do
          is_expected.to eq 0.0
        end
      end

      describe '#blue' do
        subject { color.blue }
        it 'is 0' do
          is_expected.to eq 0.0
        end
      end

      describe '#alpha' do
        subject { color.alpha }
        it 'is 0' do
          is_expected.to eq 0.0
        end
      end
    end

    context 'with no alpha' do
      let(:red)   { 10.0 }
      let(:green) { 20.0 }
      let(:blue)  { 30.0 }
      let(:color) { Color.new(red, green, blue) }

      describe '#red' do
        subject { color.red }
        it 'is assigned value' do
          is_expected.to eq red
        end
      end

      describe '#green' do
        subject { color.green }
        it 'is assigned value' do
          is_expected.to eq green
        end
      end

      describe '#blue' do
        subject { color.blue }
        it 'is assigned value' do
          is_expected.to eq blue
        end
      end

      describe '#alpha' do
        subject { color.alpha }
        it 'is 255' do
          is_expected.to eq 255.0
        end
      end
    end

    context 'with all parameters' do
      let(:red)   { 110.0 }
      let(:green) { 120.0 }
      let(:blue)  { 130.0 }
      let(:alpha) { 140.0 }
      let(:color) { Color.new(red, green, blue, alpha) }

      describe '#red' do
        subject { color.red }
        it 'is assigned value' do
          is_expected.to eq red
        end
      end

      describe '#green' do
        subject { color.green }
        it 'is assigned value' do
          is_expected.to eq green
        end
      end

      describe '#blue' do
        subject { color.blue }
        it 'is assigned value' do
          is_expected.to eq blue
        end
      end

      describe '#alpha' do
        subject { color.alpha }
        it 'is assigned value' do
          is_expected.to eq alpha
        end
      end
    end

    context 'with invalid red' do
      it 'raises a TypeError' do
        expect { Color.new(nil, 5.0, 7.0, 9.0) }.to raise_error(TypeError)
      end
    end

    context 'with invalid green' do
      it 'raises a TypeError' do
        expect { Color.new(3.0, nil, 7.0, 9.0) }.to raise_error(TypeError)
      end
    end

    context 'with invalid blue' do
      it 'raises a TypeError' do
        expect { Color.new(3.0, 5.0, nil, 9.0) }.to raise_error(TypeError)
      end
    end

    context 'with invalid alpha' do
      it 'raises a TypeError' do
        expect { Color.new(3.0, 5.0, 7.0, nil) }.to raise_error(TypeError)
      end
    end

  end

  let(:color) { Color.new }

  describe '#red' do
    subject { color.red }

    it 'is a Float' do
      is_expected.to be_a(Float)
    end

    context 'with invalid value' do
      context 'non-Float' do
        it 'raises a TypeError' do
          expect { color.red = nil }.to raise_error(TypeError)
        end
      end

      context 'less than 0' do
        it 'corrects to 0' do
          expect { color.red = -5.0 }.not_to raise_error
          is_expected.to eq 0.0
        end
      end

      context 'greater than 255' do
        it 'corrects to 255' do
          expect { color.red = 300 }.not_to raise_error
          is_expected.to eq 255.0
        end
      end
    end
  end

  describe '#green' do
    subject { color.green }

    it 'is a Float' do
      is_expected.to be_a(Float)
    end

    context 'with invalid value' do
      context 'non-Float' do
        it 'raises a TypeError' do
          expect { color.green = nil }.to raise_error(TypeError)
        end
      end

      context 'less than 0' do
        it 'corrects to 0' do
          expect { color.green = -5.0 }.not_to raise_error
          is_expected.to eq 0.0
        end
      end

      context 'greater than 255' do
        it 'corrects to 255' do
          expect { color.green = 300 }.not_to raise_error
          is_expected.to eq 255.0
        end
      end
    end
  end

  describe '#blue' do
    subject { color.blue }

    it 'is a Float' do
      is_expected.to be_a(Float)
    end

    context 'with invalid value' do
      context 'non-Float' do
        it 'raises a TypeError' do
          expect { color.blue = nil }.to raise_error(TypeError)
        end
      end

      context 'less than 0' do
        it 'corrects to 0' do
          expect { color.blue = -5.0 }.not_to raise_error
          is_expected.to eq 0.0
        end
      end

      context 'greater than 255' do
        it 'corrects to 255' do
          expect { color.blue = 300 }.not_to raise_error
          is_expected.to eq 255.0
        end
      end
    end
  end

  describe '#alpha' do
    subject { color.alpha }

    it 'is a Float' do
      is_expected.to be_a(Float)
    end

    context 'with invalid value' do
      context 'non-Float' do
        it 'raises a TypeError' do
          expect { color.alpha = nil }.to raise_error(TypeError)
        end
      end

      context 'less than 0' do
        it 'corrects to 0' do
          expect { color.alpha = -5.0 }.not_to raise_error
          is_expected.to eq 0.0
        end
      end

      context 'greater than 255' do
        it 'corrects to 255' do
          expect { color.alpha = 300 }.not_to raise_error
          is_expected.to eq 255.0
        end
      end
    end
  end

  describe '#set' do
    context 'with color components' do
      let(:red)   { 30.0 }
      let(:green) { 60.0 }
      let(:blue)  { 90.0 }
      subject(:original) { Color.new }
      subject(:color) { original.set(red, green, blue) }

      describe '#red' do
        subject { color.red }
        it 'is updated' do
          is_expected.to eq red
        end
      end

      describe '#green' do
        subject { color.green }
        it 'is updated' do
          is_expected.to eq green
        end
      end

      describe '#blue' do
        subject { color.blue }
        it 'is updated' do
          is_expected.to eq blue
        end
      end

      describe '#alpha' do
        subject { color.alpha }
        it 'is 255' do
          is_expected.to eq 255.0
        end
      end

      it 'returns itself' do
        is_expected.to be original
      end
    end

    context 'with invalid color components' do
      context 'red' do
        it 'raises a TypeError' do
          expect { Color.new.set(nil, 6.0, 9.0) }.to raise_error(TypeError)
        end
      end

      context 'green' do
        it 'raises a TypeError' do
          expect { Color.new.set(3.0, nil, 9.0) }.to raise_error(TypeError)
        end
      end

      context 'blue' do
        it 'raises a TypeError' do
          expect { Color.new.set(3.0, 6.0, nil) }.to raise_error(TypeError)
        end
      end
    end

    context 'with all components' do
      let(:red)   { 30.0 }
      let(:green) { 60.0 }
      let(:blue)  { 90.0 }
      let(:alpha) { 50.0 }
      subject(:original) { Color.new }
      subject(:color) { original.set(red, green, blue, alpha) }

      describe '#red' do
        subject { color.red }
        it 'is updated' do
          is_expected.to eq red
        end
      end

      describe '#green' do
        subject { color.green }
        it 'is updated' do
          is_expected.to eq green
        end
      end

      describe '#blue' do
        subject { color.blue }
        it 'is updated' do
          is_expected.to eq blue
        end
      end

      describe '#alpha' do
        subject { color.alpha }
        it 'is updated' do
          is_expected.to eq alpha
        end
      end

      it 'returns itself' do
        is_expected.to be original
      end
    end

    context 'with invalid components' do
      context 'red' do
        it 'raises a TypeError' do
          expect { Color.new.set(nil, 5.0, 10.0, 15.0) }.to raise_error(TypeError)
        end
      end

      context 'green' do
        it 'raises a TypeError' do
          expect { Color.new.set(0.0, nil, 10.0, 15.0) }.to raise_error(TypeError)
        end
      end

      context 'blue' do
        it 'raises a TypeError' do
          expect { Color.new.set(0.0, 5.0, nil, 15.0) }.to raise_error(TypeError)
        end
      end

      context 'alpha' do
        it 'raises a TypeError' do
          expect { Color.new.set(0.0, 5.0, 10.0, nil) }.to raise_error(TypeError)
        end
      end
    end

    context 'with color' do
      let(:red)   { 30.0 }
      let(:green) { 60.0 }
      let(:blue)  { 90.0 }
      let(:alpha) { 50.0 }
      let(:other) { Color.new(red, green, blue, alpha) }
      subject(:original) { Color.new }
      subject(:color) { original.set(other) }

      describe '#red' do
        subject { color.red }
        it 'is updated' do
          is_expected.to eq red
        end
      end

      describe '#green' do
        subject { color.green }
        it 'is updated' do
          is_expected.to eq green
        end
      end

      describe '#blue' do
        subject { color.blue }
        it 'is updated' do
          is_expected.to eq blue
        end
      end

      describe '#alpha' do
        subject { color.alpha }
        it 'is updated' do
          is_expected.to eq alpha
        end
      end

      it 'returns itself' do
        is_expected.to be original
      end
    end

    context 'with invalid color' do
      it 'raises a TypeError' do
        expect { Color.new.set(nil) }.to raise_error(TypeError)
      end
    end
  end

  describe '#to_s' do
    let(:red)   { 210.0 }
    let(:green) { 220.0 }
    let(:blue)  { 230.0 }
    let(:alpha) { 240.0 }
    let(:color) { Color.new(red, green, blue, alpha) }
    subject { color.to_s }

    it 'contains the component values' do
      is_expected.to eq sprintf("(%f, %f, %f, %f)", red, green, blue, alpha)
    end
  end

  describe '#==' do
    subject { color1 == color2 }

    context 'equal colors' do
      let(:color1) { Color.new(10, 20, 30, 40) }
      let(:color2) { Color.new(10, 20, 30, 40) }

      it 'is true' do
        is_expected.to eq true
      end
    end

    context 'different colors' do
      let(:color1) { Color.new(10, 20, 30, 40) }
      let(:color2) { Color.new(50, 60, 70, 80) }

      it 'is false' do
        is_expected.to eq false
      end
    end
  end

  describe '#_dump' do
    let(:red)   { 123.0 }
    let(:green) {  45.0 }
    let(:blue)  {  32.0 }
    let(:alpha) { 128.0 }
    let(:color) { Color.new(red, green, blue, alpha) }
    let(:bytes) { [0, 0, 0, 0, 0, 0xc0, 0x5e, 0x40, 0, 0, 0, 0, 0, 0x80, 0x46, 0x40, 0, 0, 0, 0, 0, 0, 0x40, 0x40, 0, 0, 0, 0, 0, 0, 0x60, 0x40] }
    subject { color._dump(10).unpack('C*') }

    it 'generates expected result' do
      is_expected.to eq bytes
    end
  end

  describe '._load' do
    let(:red)   { 123.0 }
    let(:green) {  45.0 }
    let(:blue)  {  32.0 }
    let(:alpha) { 128.0 }
    let(:bytes) { [0, 0, 0, 0, 0, 0xc0, 0x5e, 0x40, 0, 0, 0, 0, 0, 0x80, 0x46, 0x40, 0, 0, 0, 0, 0, 0, 0x40, 0x40, 0, 0, 0, 0, 0, 0, 0x60, 0x40] }
    subject(:color) { Color._load(bytes.pack('C*')) }

    describe '#red' do
      subject { color.red }
      it 'is the expected value' do
        is_expected.to eq red
      end
    end

    describe '#green' do
      subject { color.green }
      it 'is the expected value' do
        is_expected.to eq green
      end
    end

    describe '#blue' do
      subject { color.blue }
      it 'is the expected value' do
        is_expected.to eq blue
      end
    end

    describe '#alpha' do
      subject { color.alpha }
      it 'is the expected value' do
        is_expected.to eq alpha
      end
    end
  end

end
