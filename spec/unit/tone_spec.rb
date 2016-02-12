require_relative '../spec_helper'

RSpec.describe Tone do

  describe '#new' do

    context 'with no parameters' do
      let(:tone) { Tone.new }

      describe '#red' do
        subject { tone.red }
        it 'is 0' do
          is_expected.to eq 0.0
        end
      end

      describe '#green' do
        subject { tone.green }
        it 'is 0' do
          is_expected.to eq 0.0
        end
      end

      describe '#blue' do
        subject { tone.blue }
        it 'is 0' do
          is_expected.to eq 0.0
        end
      end

      describe '#gray' do
        subject { tone.gray }
        it 'is 0' do
          is_expected.to eq 0.0
        end
      end
    end

    context 'with no gray' do
      let(:red)   { 10.0 }
      let(:green) { 20.0 }
      let(:blue)  { 30.0 }
      let(:tone) { Tone.new(red, green, blue) }

      describe '#red' do
        subject { tone.red }
        it 'is assigned value' do
          is_expected.to eq red
        end
      end

      describe '#green' do
        subject { tone.green }
        it 'is assigned value' do
          is_expected.to eq green
        end
      end

      describe '#blue' do
        subject { tone.blue }
        it 'is assigned value' do
          is_expected.to eq blue
        end
      end

      describe '#gray' do
        subject { tone.gray }
        it 'is 0' do
          is_expected.to eq 0.0
        end
      end
    end

    context 'with all parameters' do
      let(:red)   { 110.0 }
      let(:green) { 120.0 }
      let(:blue)  { 130.0 }
      let(:gray)  { 140.0 }
      let(:tone) { Tone.new(red, green, blue, gray) }

      describe '#red' do
        subject { tone.red }
        it 'is assigned value' do
          is_expected.to eq red
        end
      end

      describe '#green' do
        subject { tone.green }
        it 'is assigned value' do
          is_expected.to eq green
        end
      end

      describe '#blue' do
        subject { tone.blue }
        it 'is assigned value' do
          is_expected.to eq blue
        end
      end

      describe '#gray' do
        subject { tone.gray }
        it 'is assigned value' do
          is_expected.to eq gray
        end
      end
    end

    context 'with invalid red' do
      it 'raises a TypeError' do
        expect { Tone.new(nil, 5.0, 7.0, 9.0) }.to raise_error(TypeError)
      end
    end

    context 'with invalid green' do
      it 'raises a TypeError' do
        expect { Tone.new(3.0, nil, 7.0, 9.0) }.to raise_error(TypeError)
      end
    end

    context 'with invalid blue' do
      it 'raises a TypeError' do
        expect { Tone.new(3.0, 5.0, nil, 9.0) }.to raise_error(TypeError)
      end
    end

    context 'with invalid gray' do
      it 'raises a TypeError' do
        expect { Tone.new(3.0, 5.0, 7.0, nil) }.to raise_error(TypeError)
      end
    end

  end

  let(:tone) { Tone.new }

  describe '#red' do
    subject { tone.red }

    it 'is a Float' do
      is_expected.to be_a(Float)
    end

    context 'with invalid value' do
      context 'non-Float' do
        it 'raises a TypeError' do
          expect { tone.red = nil }.to raise_error(TypeError)
        end
      end

      context 'less than -255' do
        it 'corrects to -255' do
          expect { tone.red = -300.0 }.not_to raise_error
          is_expected.to eq(-255.0)
        end
      end

      context 'greater than 255' do
        it 'corrects to 255' do
          expect { tone.red = 300 }.not_to raise_error
          is_expected.to eq 255.0
        end
      end
    end
  end

  describe '#green' do
    subject { tone.green }

    it 'is a Float' do
      is_expected.to be_a(Float)
    end

    context 'with invalid value' do
      context 'non-Float' do
        it 'raises a TypeError' do
          expect { tone.green = nil }.to raise_error(TypeError)
        end
      end

      context 'less than -255' do
        it 'corrects to -255' do
          expect { tone.green = -300.0 }.not_to raise_error
          is_expected.to eq(-255.0)
        end
      end

      context 'greater than 255' do
        it 'corrects to 255' do
          expect { tone.green = 300 }.not_to raise_error
          is_expected.to eq 255.0
        end
      end
    end
  end

  describe '#blue' do
    subject { tone.blue }

    it 'is a Float' do
      is_expected.to be_a(Float)
    end

    context 'with invalid value' do
      context 'non-Float' do
        it 'raises a TypeError' do
          expect { tone.blue = nil }.to raise_error(TypeError)
        end
      end

      context 'less than -255' do
        it 'corrects to -255' do
          expect { tone.blue = -300.0 }.not_to raise_error
          is_expected.to eq(-255.0)
        end
      end

      context 'greater than 255' do
        it 'corrects to 255' do
          expect { tone.blue = 300 }.not_to raise_error
          is_expected.to eq 255.0
        end
      end
    end
  end

  describe '#gray' do
    subject { tone.gray }

    it 'is a Float' do
      is_expected.to be_a(Float)
    end

    context 'with invalid value' do
      context 'non-Float' do
        it 'raises a TypeError' do
          expect { tone.gray = nil }.to raise_error(TypeError)
        end
      end

      context 'less than 0' do
        it 'corrects to 0' do
          expect { tone.gray = -5.0 }.not_to raise_error
          is_expected.to eq 0.0
        end
      end

      context 'greater than 255' do
        it 'corrects to 255' do
          expect { tone.gray = 300 }.not_to raise_error
          is_expected.to eq 255.0
        end
      end
    end
  end

  describe '#set' do
    context 'with color components' do
      let(:red)   { 130.0 }
      let(:green) { -60.0 }
      let(:blue)  { 190.0 }
      subject(:original) { Tone.new }
      subject(:tone) { original.set(red, green, blue) }

      describe '#red' do
        subject { tone.red }
        it 'is updated' do
          is_expected.to eq red
        end
      end

      describe '#green' do
        subject { tone.green }
        it 'is updated' do
          is_expected.to eq green
        end
      end

      describe '#blue' do
        subject { tone.blue }
        it 'is updated' do
          is_expected.to eq blue
        end
      end

      describe '#gray' do
        subject { tone.gray }
        it 'is 0' do
          is_expected.to eq 0.0
        end
      end

      it 'returns itself' do
        is_expected.to be original
      end
    end

    context 'with invalid color components' do
      context 'red' do
        it 'raises a TypeError' do
          expect { Tone.new.set(nil, 6.0, 9.0) }.to raise_error(TypeError)
        end
      end

      context 'green' do
        it 'raises a TypeError' do
          expect { Tone.new.set(3.0, nil, 9.0) }.to raise_error(TypeError)
        end
      end

      context 'blue' do
        it 'raises a TypeError' do
          expect { Tone.new.set(3.0, 6.0, nil) }.to raise_error(TypeError)
        end
      end
    end

    context 'with all components' do
      let(:red)   { -30.0 }
      let(:green) { 160.0 }
      let(:blue)  { -90.0 }
      let(:gray)  { 150.0 }
      subject(:original) { Tone.new }
      subject(:tone) { original.set(red, green, blue, gray) }

      describe '#red' do
        subject { tone.red }
        it 'is updated' do
          is_expected.to eq red
        end
      end

      describe '#green' do
        subject { tone.green }
        it 'is updated' do
          is_expected.to eq green
        end
      end

      describe '#blue' do
        subject { tone.blue }
        it 'is updated' do
          is_expected.to eq blue
        end
      end

      describe '#gray' do
        subject { tone.gray }
        it 'is updated' do
          is_expected.to eq gray
        end
      end

      it 'returns itself' do
        is_expected.to be original
      end
    end

    context 'with invalid components' do
      context 'red' do
        it 'raises a TypeError' do
          expect { Tone.new.set(nil, 5.0, 10.0, 15.0) }.to raise_error(TypeError)
        end
      end

      context 'green' do
        it 'raises a TypeError' do
          expect { Tone.new.set(0.0, nil, 10.0, 15.0) }.to raise_error(TypeError)
        end
      end

      context 'blue' do
        it 'raises a TypeError' do
          expect { Tone.new.set(0.0, 5.0, nil, 15.0) }.to raise_error(TypeError)
        end
      end

      context 'gray' do
        it 'raises a TypeError' do
          expect { Tone.new.set(0.0, 5.0, 10.0, nil) }.to raise_error(TypeError)
        end
      end
    end

    context 'with tone' do
      let(:red)   { -30.0 }
      let(:green) { -60.0 }
      let(:blue)  { -90.0 }
      let(:gray)  { 150.0 }
      let(:other) { Tone.new(red, green, blue, gray) }
      subject(:original) { Tone.new }
      subject(:tone) { original.set(other) }

      describe '#red' do
        subject { tone.red }
        it 'is updated' do
          is_expected.to eq red
        end
      end

      describe '#green' do
        subject { tone.green }
        it 'is updated' do
          is_expected.to eq green
        end
      end

      describe '#blue' do
        subject { tone.blue }
        it 'is updated' do
          is_expected.to eq blue
        end
      end

      describe '#gray' do
        subject { tone.gray }
        it 'is updated' do
          is_expected.to eq gray
        end
      end

      it 'returns itself' do
        is_expected.to be original
      end
    end

    context 'with invalid tone' do
      it 'raises a TypeError' do
        expect { Tone.new.set(nil) }.to raise_error(TypeError)
      end
    end
  end

  describe '#to_s' do
    let(:red)   { 210.0 }
    let(:green) { 220.0 }
    let(:blue)  { 230.0 }
    let(:gray)  { 240.0 }
    let(:tone) { Tone.new(red, green, blue, gray) }
    subject { tone.to_s }

    it 'contains the component values' do
      is_expected.to eq sprintf("(%f, %f, %f, %f)", red, green, blue, gray)
    end
  end

  describe '#==' do
    subject { tone1 == tone2 }

    context 'equal tones' do
      let(:tone1) { Tone.new(10, 20, 30, 40) }
      let(:tone2) { Tone.new(10, 20, 30, 40) }

      it 'is true' do
        is_expected.to eq true
      end
    end

    context 'different tones' do
      let(:tone1) { Tone.new(10, 20, 30, 40) }
      let(:tone2) { Tone.new(50, 60, 70, 80) }

      it 'is false' do
        is_expected.to eq false
      end
    end
  end

  describe '#_dump' do
    let(:red)   { 123.0 }
    let(:green) {  45.0 }
    let(:blue)  {  32.0 }
    let(:gray)  { 128.0 }
    let(:tone) { Tone.new(red, green, blue, gray) }
    let(:bytes) { [0, 0, 0, 0, 0, 0xc0, 0x5e, 0x40, 0, 0, 0, 0, 0, 0x80, 0x46, 0x40, 0, 0, 0, 0, 0, 0, 0x40, 0x40, 0, 0, 0, 0, 0, 0, 0x60, 0x40] }
    subject { tone._dump(10).unpack('C*') }

    it 'generates expected result' do
      is_expected.to eq bytes
    end
  end

  describe '._load' do
    let(:red)   { 123.0 }
    let(:green) {  45.0 }
    let(:blue)  {  32.0 }
    let(:gray)  { 128.0 }
    let(:bytes) { [0, 0, 0, 0, 0, 0xc0, 0x5e, 0x40, 0, 0, 0, 0, 0, 0x80, 0x46, 0x40, 0, 0, 0, 0, 0, 0, 0x40, 0x40, 0, 0, 0, 0, 0, 0, 0x60, 0x40] }
    subject(:tone) { Tone._load(bytes.pack('C*')) }

    describe '#red' do
      subject { tone.red }
      it 'is the expected value' do
        is_expected.to eq red
      end
    end

    describe '#green' do
      subject { tone.green }
      it 'is the expected value' do
        is_expected.to eq green
      end
    end

    describe '#blue' do
      subject { tone.blue }
      it 'is the expected value' do
        is_expected.to eq blue
      end
    end

    describe '#gray' do
      subject { tone.gray }
      it 'is the expected value' do
        is_expected.to eq gray
      end
    end
  end

end
