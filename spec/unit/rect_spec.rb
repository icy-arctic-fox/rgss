require_relative '../spec_helper'

RSpec.describe Rect do

  describe '#new' do

    context 'with no parameters' do
      let(:rect) { Rect.new }

      describe '#x' do
        subject { rect.x }
        it 'is 0' do
          is_expected.to eq 0
        end
      end

      describe '#y' do
        subject { rect.y }
        it 'is 0' do
          is_expected.to eq 0
        end
      end

      describe '#width' do
        subject { rect.width }
        it 'is 0' do
          is_expected.to eq 0
        end
      end

      describe '#height' do
        subject { rect.height }
        it 'is 0' do
          is_expected.to eq 0
        end
      end
    end

    context 'with parameters' do
      let(:x)      { 25 }
      let(:y)      { 50 }
      let(:width)  { 32 }
      let(:height) { 64 }
      let(:rect)   { Rect.new(x, y, width, height) }

      describe '#x' do
        subject { rect.x }
        it 'is assigned value' do
          is_expected.to eq x
        end
      end

      describe '#y' do
        subject { rect.y }
        it 'is assigned value' do
          is_expected.to eq y
        end
      end

      describe '#width' do
        subject { rect.width }
        it 'is assigned value' do
          is_expected.to eq width
        end
      end

      describe '#height' do
        subject { rect.height }
        it 'is assigned value' do
          is_expected.to eq height
        end
      end
    end

    context 'with invalid x' do
      it 'raises a TypeError' do
        expect { Rect.new(nil, 5, 7, 9) }.to raise_error(TypeError)
      end
    end

    context 'with invalid y' do
      it 'raises a TypeError' do
        expect { Rect.new(3, nil, 7, 9) }.to raise_error(TypeError)
      end
    end

    context 'with invalid width' do
      it 'raises a TypeError' do
        expect { Rect.new(3, 5, nil, 9) }.to raise_error(TypeError)
      end
    end

    context 'with invalid height' do
      it 'raises a TypeError' do
        expect { Rect.new(3, 5, 7, nil) }.to raise_error(TypeError)
      end
    end

  end

  let(:rect) { Rect.new }

  describe '#x' do
    subject { rect.x }

    it 'is a Fixnum' do
      is_expected.to be_a(Fixnum)
    end

    context 'with invalid value' do
      context 'non-Fixnum' do
        it 'raises a TypeError' do
          expect { rect.x = nil }.to raise_error(TypeError)
        end
      end
    end
  end

  describe '#y' do
    subject { rect.y }

    it 'is a Fixnum' do
      is_expected.to be_a(Fixnum)
    end

    context 'with invalid value' do
      context 'non-Fixnum' do
        it 'raises a TypeError' do
          expect { rect.y = nil }.to raise_error(TypeError)
        end
      end
    end
  end

  describe '#width' do
    subject { rect.width }

    it 'is a Fixnum' do
      is_expected.to be_a(Fixnum)
    end

    it 'allows less than 0' do
      expect { rect.width = -5 }.not_to raise_error
      is_expected.to eq(-5)
    end

    context 'with invalid value' do
      context 'non-Fixnum' do
        it 'raises a TypeError' do
          expect { rect.width = nil }.to raise_error(TypeError)
        end
      end
    end
  end

  describe '#height' do
    subject { rect.height }

    it 'is a Fixnum' do
      is_expected.to be_a(Fixnum)
    end

    it 'allows less than 0' do
      expect { rect.height = -5 }.not_to raise_error
      is_expected.to eq(-5)
    end

    context 'with invalid value' do
      context 'non-Fixnum' do
        it 'raises a TypeError' do
          expect { rect.height = nil }.to raise_error(TypeError)
        end
      end
    end
  end

  describe '#set' do
    context 'with components' do
      let(:x)      { 100 }
      let(:y)      { 200 }
      let(:width)  { 128 }
      let(:height) { 160 }
      subject(:original) { Rect.new }
      subject(:rect) { original.set(x, y, width, height) }

      describe '#x' do
        subject { rect.x }
        it 'is updated' do
          is_expected.to eq x
        end
      end

      describe '#y' do
        subject { rect.y }
        it 'is updated' do
          is_expected.to eq y
        end
      end

      describe '#width' do
        subject { rect.width }
        it 'is updated' do
          is_expected.to eq width
        end
      end

      describe '#height' do
        subject { rect.height }
        it 'is updated' do
          is_expected.to eq height
        end
      end

      it 'returns itself' do
        is_expected.to be original
      end
    end

    context 'with invalid components' do
      context 'x' do
        it 'raises a TypeError' do
          expect { Rect.new.set(nil, 5, 10, 15) }.to raise_error(TypeError)
        end
      end

      context 'y' do
        it 'raises a TypeError' do
          expect { Rect.new.set(0, nil, 10, 15) }.to raise_error(TypeError)
        end
      end

      context 'width' do
        it 'raises a TypeError' do
          expect { Rect.new.set(0, 5, nil, 15) }.to raise_error(TypeError)
        end
      end

      context 'height' do
        it 'raises a TypeError' do
          expect { Rect.new.set(0, 5, 10, nil) }.to raise_error(TypeError)
        end
      end
    end

    context 'with rectangle' do
      let(:x)      { 32 }
      let(:y)      { 24 }
      let(:width)  { 10 }
      let(:height) { 20 }
      let(:other)  { Rect.new(x, y, width, height) }
      subject(:original) { Rect.new }
      subject(:rect) { original.set(other) }

      describe '#x' do
        subject { rect.x }
        it 'is updated' do
          is_expected.to eq x
        end
      end

      describe '#y' do
        subject { rect.y }
        it 'is updated' do
          is_expected.to eq y
        end
      end

      describe '#width' do
        subject { rect.width }
        it 'is updated' do
          is_expected.to eq width
        end
      end

      describe '#height' do
        subject { rect.height }
        it 'is updated' do
          is_expected.to eq height
        end
      end

      it 'returns itself' do
        is_expected.to be original
      end
    end

    context 'with invalid rectangle' do
      it 'raises a TypeError' do
        expect { Rect.new.set(nil) }.to raise_error(TypeError)
      end
    end
  end

  describe '#empty' do
    subject(:original) { Rect.new(10, 20, 30, 40) }
    subject(:rect) { original.empty }

    describe '#x' do
      subject { rect.x }
      it 'set to 0' do
        is_expected.to eq 0
      end
    end

    describe '#y' do
      subject { rect.y }
      it 'set to 0' do
        is_expected.to eq 0
      end
    end

    describe '#width' do
      subject { rect.width }
      it 'set to 0' do
        is_expected.to eq 0
      end
    end

    describe '#height' do
      subject { rect.height }
      it 'set to 0' do
        is_expected.to eq 0
      end
    end

    it 'returns itself' do
      is_expected.to be original
    end
  end

  describe '#to_s' do
    let(:x)      {  20 }
    let(:y)      {  30 }
    let(:width)  { 620 }
    let(:height) { 450 }
    let(:rect)   { Rect.new(x, y, width, height) }
    subject { rect.to_s }

    it 'contains the component values' do
      is_expected.to eq "(#{[x, y, width, height].join(', ')})"
    end
  end

  describe '#==' do
    subject { rect1 == rect2 }

    context 'equal rects' do
      let(:rect1) { Rect.new(10, 20, 30, 40) }
      let(:rect2) { Rect.new(10, 20, 30, 40) }

      it 'is true' do
        is_expected.to eq true
      end
    end

    context 'different rects' do
      let(:rect1) { Rect.new(10, 20, 30, 40) }
      let(:rect2) { Rect.new(50, 60, 70, 80) }

      it 'is false' do
        is_expected.to eq false
      end
    end

    context 'non-rect' do
      let(:rect1) { Rect.new(10, 20, 30, 40) }
      let(:rect2) { nil }

      it 'is false' do
        is_expected.to eq false
      end
    end
  end

  describe '#_dump' do
    let(:x)      {  20 }
    let(:y)      {  30 }
    let(:width)  { 620 }
    let(:height) { 450 }
    let(:rect)   { Rect.new(x, y, width, height) }
    let(:bytes)  { [20, 0, 0, 0, 30, 0, 0, 0, 108, 2, 0, 0, 194, 1, 0, 0] }
    subject { rect._dump(10).unpack('C*') }

    it 'generates expected result' do
      is_expected.to eq bytes
    end
  end

  describe '._load' do
    let(:x)      {  20 }
    let(:y)      {  30 }
    let(:width)  { 620 }
    let(:height) { 450 }
    let(:bytes)  { [20, 0, 0, 0, 30, 0, 0, 0, 108, 2, 0, 0, 194, 1, 0, 0] }
    subject(:rect) { Rect._load(bytes.pack('C*')) }

    describe '#x' do
      subject { rect.x }
      it 'is the expected value' do
        is_expected.to eq x
      end
    end

    describe '#y' do
      subject { rect.y }
      it 'is the expected value' do
        is_expected.to eq y
      end
    end

    describe '#width' do
      subject { rect.width }
      it 'is the expected value' do
        is_expected.to eq width
      end
    end

    describe '#height' do
      subject { rect.height }
      it 'is the expected value' do
        is_expected.to eq height
      end
    end
  end

end
