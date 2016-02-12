require_relative '../spec_helper'

RSpec.describe Font do

  describe '#new' do

    context 'with no parameters' do
      let(:font) { Font.new }

      describe '#name' do
        subject { font.name }
        it 'is the default' do
          is_expected.to eq Font.default_name
        end
      end

      describe '#size' do
        subject { font.size }
        it 'is the default' do
          is_expected.to eq Font.default_size
        end
      end

      describe '#bold' do
        subject { font.bold }
        it 'is the default' do
          is_expected.to eq Font.default_bold
        end
      end

      describe '#italic' do
        subject { font.italic }
        it 'is the default' do
          is_expected.to eq Font.default_italic
        end
      end

      describe '#outline' do
        subject { font.outline }
        it 'is the default' do
          is_expected.to eq Font.default_outline
        end
      end

      describe '#shadow' do
        subject { font.shadow }
        it 'is the default' do
          is_expected.to eq Font.default_shadow
        end
      end

      describe '#color' do
        subject { font.color }
        it 'is the default' do
          is_expected.to eq Font.default_color
        end
      end

      describe '#out_color' do
        subject { font.out_color }
        it 'is the default' do
          is_expected.to eq Font.default_out_color
        end
      end
    end

    context 'with font name' do
      let(:name) { 'Verdana' }
      let(:font) { Font.new(name) }

      describe '#name' do
        subject { font.name }
        it 'is the set value' do
          is_expected.to eq name
        end
      end

      describe '#size' do
        subject { font.size }
        it 'is the default' do
          is_expected.to eq Font.default_size
        end
      end

      describe '#bold' do
        subject { font.bold }
        it 'is the default' do
          is_expected.to eq Font.default_bold
        end
      end

      describe '#italic' do
        subject { font.italic }
        it 'is the default' do
          is_expected.to eq Font.default_italic
        end
      end

      describe '#outline' do
        subject { font.outline }
        it 'is the default' do
          is_expected.to eq Font.default_outline
        end
      end

      describe '#shadow' do
        subject { font.shadow }
        it 'is the default' do
          is_expected.to eq Font.default_shadow
        end
      end

      describe '#color' do
        subject { font.color }
        it 'is the default' do
          is_expected.to eq Font.default_color
        end
      end

      describe '#out_color' do
        subject { font.out_color }
        it 'is the default' do
          is_expected.to eq Font.default_out_color
        end
      end
    end

    context 'with array of font names' do
      let(:names) { %w(Myriad Verdana Arial) }
      let(:font) { Font.new(names) }

      describe '#name' do
        subject { font.name }
        it 'is the set values' do
          is_expected.to eq names
        end
      end

      describe '#size' do
        subject { font.size }
        it 'is the default' do
          is_expected.to eq Font.default_size
        end
      end

      describe '#bold' do
        subject { font.bold }
        it 'is the default' do
          is_expected.to eq Font.default_bold
        end
      end

      describe '#italic' do
        subject { font.italic }
        it 'is the default' do
          is_expected.to eq Font.default_italic
        end
      end

      describe '#outline' do
        subject { font.outline }
        it 'is the default' do
          is_expected.to eq Font.default_outline
        end
      end

      describe '#shadow' do
        subject { font.shadow }
        it 'is the default' do
          is_expected.to eq Font.default_shadow
        end
      end

      describe '#color' do
        subject { font.color }
        it 'is the default' do
          is_expected.to eq Font.default_color
        end
      end

      describe '#out_color' do
        subject { font.out_color }
        it 'is the default' do
          is_expected.to eq Font.default_out_color
        end
      end
    end

    context 'with invalid font name' do
      # I don't know why there's no validation here, vanilla RGSS3 doesn't complain.
      it 'does not raise an error' do
        expect { Font.new(nil) }.to_not raise_error
      end
    end

    context 'with font name and size' do
      let(:name) { 'Verdana' }
      let(:size) { 32 }
      let(:font) { Font.new(name, size) }

      describe '#name' do
        subject { font.name }
        it 'is the set value' do
          is_expected.to eq name
        end
      end

      describe '#size' do
        subject { font.size }
        it 'is the set value' do
          is_expected.to eq size
        end
      end

      describe '#bold' do
        subject { font.bold }
        it 'is the default' do
          is_expected.to eq Font.default_bold
        end
      end

      describe '#italic' do
        subject { font.italic }
        it 'is the default' do
          is_expected.to eq Font.default_italic
        end
      end

      describe '#outline' do
        subject { font.outline }
        it 'is the default' do
          is_expected.to eq Font.default_outline
        end
      end

      describe '#shadow' do
        subject { font.shadow }
        it 'is the default' do
          is_expected.to eq Font.default_shadow
        end
      end

      describe '#color' do
        subject { font.color }
        it 'is the default' do
          is_expected.to eq Font.default_color
        end
      end

      describe '#out_color' do
        subject { font.out_color }
        it 'is the default' do
          is_expected.to eq Font.default_out_color
        end
      end
    end

    context 'with invalid size' do
      it 'raises a TypeError' do
        expect { Font.new('Verdana', nil) }.to raise_error(TypeError)
      end
    end
  end

  let(:font) { Font.new }

  describe '#name' do
    subject { font.name }

    # Note: The following tests use "be" instead of "eq".
    # This is intentional as RGSS doesn't dup the instance, it uses the original reference.
    # This means any modifications to the original instance (especially arrays), affect the font.

    context 'with single font name' do
      let(:value) { 'Comic Sans' }

      it 'stores a value' do
        font.name = value
        is_expected.to be value
      end
    end

    context 'with multiple font names' do
      let(:value) { %w(Myriad Verdana Arial) }

      it 'stores a value' do
        font.name = value
        is_expected.to be value
      end
    end

    context 'with invalid value' do
      let(:value) { nil }

      it 'does not raise an error' do
        expect { font.name = value }.to_not raise_error
      end

      it 'stores a value' do
        font.name = value
        is_expected.to be value
      end
    end
  end

  describe '#size' do
    subject { font.size }

    context 'with valid value' do
      let(:value) { 20 }

      it 'stores a value' do
        font.size = value
        is_expected.to eq value
      end
    end

    context 'with invalid value' do
      let(:value) { 'foobar' }

      it 'raises a TypeError' do
        expect { font.size = value }.to raise_error(TypeError)
      end
    end
  end

  describe '#bold' do
    subject { font.bold }

    context 'with valid value' do
      let(:value) { true }

      it 'stores a value' do
        font.bold = value
        is_expected.to eq value
      end
    end

    context 'with invalid value' do
      let(:value) { 'foobar' }

      it 'stores the truthy value' do
        font.bold = value
        is_expected.to eq !!value
      end
    end
  end

  describe '#italic' do
    subject { font.italic }

    context 'with valid value' do
      let(:value) { true }

      it 'stores a value' do
        font.italic = value
        is_expected.to eq value
      end
    end

    context 'with invalid value' do
      let(:value) { 'foobar' }

      it 'stores the truthy value' do
        font.italic = value
        is_expected.to eq !!value
      end
    end
  end

  describe '#outline' do
    subject { font.outline }

    context 'with valid value' do
      let(:value) { false }

      it 'stores a value' do
        font.outline = value
        is_expected.to eq value
      end
    end

    context 'with invalid value' do
      let(:value) { nil }

      it 'stores the truthy value' do
        font.outline = value
        is_expected.to eq !!value
      end
    end
  end

  describe '#shadow' do
    subject { font.shadow }

    context 'with valid value' do
      let(:value) { true }

      it 'stores a value' do
        font.shadow = value
        is_expected.to eq value
      end
    end

    context 'with invalid value' do
      let(:value) { 'foobar' }

      it 'stores the truthy value' do
        font.shadow = value
        is_expected.to eq !!value
      end
    end
  end

  describe '#color' do
    subject { font.color }

    context 'with valid value' do
      let(:value) { Color.new(20, 30, 40, 50) }

      it 'stores a value' do
        font.color = value
        is_expected.to eq value
      end
    end

    context 'with invalid value' do
      let(:value) { 'foobar' }

      it 'raises a TypeError' do
        expect { font.color = value }.to raise_error(TypeError)
      end
    end
  end

  describe '#out_color' do
    subject { font.out_color }

    context 'with valid value' do
      let(:value) { Color.new(20, 30, 40, 50) }

      it 'stores a value' do
        font.out_color = value
        is_expected.to eq value
      end
    end

    context 'with invalid value' do
      let(:value) { 'foobar' }

      it 'raises a TypeError' do
        expect { font.out_color = value }.to raise_error(TypeError)
      end
    end
  end

  describe '.default_name' do
    subject { Font.default_name }

    # Note: The following tests use "be" instead of "eq".
    # This is intentional as RGSS doesn't dup the instance, it uses the original reference.
    # This means any modifications to the original instance (especially arrays), affect the font.

    describe 'initial value' do
      let(:value) { 'VL Gothic' }
      it 'is the expected value' do
        is_expected.to be value
      end
    end

    before :each do
      @original_value = Font.default_name
    end
    after :each do
      Font.default_name = @original_value
    end

    context 'with single font name' do
      let(:value) { 'Comic Sans' }

      it 'stores a value' do
        Font.default_name = value
        is_expected.to be value
      end

      it 'affects new instances' do
        Font.default_name = value
        expect(Font.new.name).to be value
      end
    end

    context 'with multiple font names' do
      let(:value) { %w(Myriad Verdana Arial) }

      it 'stores a value' do
        Font.default_name = value
        is_expected.to be value
      end

      it 'affects new instances' do
        Font.default_name = value
        expect(Font.new.name).to be value
      end
    end

    context 'with invalid value' do
      let(:value) { nil }

      it 'does not raise an error' do
        expect { Font.default_name = value }.to_not raise_error
      end

      it 'stores a value' do
        Font.default_name = value
        is_expected.to be value
      end

      it 'affects new instances' do
        Font.default_name = value
        expect(Font.new.name).to be value
      end
    end
  end

  describe '.default_size' do
    subject { Font.default_size }

    describe 'initial value' do
      let(:value) { 24 }
      it 'is the expected value' do
        is_expected.to eq value
      end
    end

    let(:value) { 28 }
    before :each do
      @original_value = Font.default_size
    end
    after :each do
      Font.default_size = @original_value
    end

    it 'stores a value' do
      Font.default_size = value
      is_expected.to eq value
    end

    it 'affects new instances' do
      Font.default_size = value
      expect(Font.new.size).to eq value
    end

    context 'with invalid value' do
      let(:value) { 'foobar' }
      it 'raises a TypeError' do
        expect { Font.default_size = value }.to raise_error(TypeError)
      end
    end
  end

  describe '.default_bold' do
    subject { Font.default_bold }

    describe 'initial value' do
      let(:value) { false }
      it 'is the expected value' do
        is_expected.to eq value
      end
    end

    let(:value) { true }
    before :each do
      @original_value = Font.default_bold
    end
    after :each do
      Font.default_bold = @original_value
    end

    it 'stores a value' do
      Font.default_bold = value
      is_expected.to eq value
    end

    it 'affects new instances' do
      Font.default_bold = value
      expect(Font.new.bold).to eq value
    end

    context 'with invalid value' do
      let(:value) { 'foobar' }

      it 'does not raise an error' do
        expect { Font.default_bold = value }.not_to raise_error
      end

      it 'stores the value' do
        Font.default_bold = value
        is_expected.to eq value
      end

      it 'applies the truthy value to new instances' do
        Font.default_bold = value
        expect(Font.new.bold).to eq !!value
      end
    end
  end

  describe '.default_italic' do
    subject { Font.default_italic }

    describe 'initial value' do
      let(:value) { false }
      it 'is the expected value' do
        is_expected.to eq value
      end
    end

    let(:value) { true }
    before :each do
      @original_value = Font.default_italic
    end
    after :each do
      Font.default_italic = @original_value
    end

    it 'stores a value' do
      Font.default_italic = value
      is_expected.to eq value
    end

    it 'affects new instances' do
      Font.default_italic = value
      expect(Font.new.italic).to eq value
    end

    context 'with invalid value' do
      let(:value) { 'foobar' }

      it 'does not raise an error' do
        expect { Font.default_italic = value }.not_to raise_error
      end

      it 'stores the value' do
        Font.default_italic = value
        is_expected.to eq value
      end

      it 'applies the truthy value to new instances' do
        Font.default_italic = value
        expect(Font.new.italic).to eq !!value
      end
    end
  end

  describe '.default_shadow' do
    subject { Font.default_shadow }

    describe 'initial value' do
      let(:value) { false }
      it 'is the expected value' do
        is_expected.to eq value
      end
    end

    let(:value) { true }
    before :each do
      @original_value = Font.default_shadow
    end
    after :each do
      Font.default_shadow = @original_value
    end

    it 'stores a value' do
      Font.default_shadow = value
      is_expected.to eq value
    end

    it 'affects new instances' do
      Font.default_shadow = value
      expect(Font.new.shadow).to eq value
    end

    context 'with invalid value' do
      let(:value) { 'foobar' }

      it 'does not raise an error' do
        expect { Font.default_shadow = value }.not_to raise_error
      end

      it 'stores the value' do
        Font.default_shadow = value
        is_expected.to eq value
      end

      it 'applies the truthy value to new instances' do
        Font.default_shadow = value
        expect(Font.new.shadow).to eq !!value
      end
    end
  end

  describe '.default_outline' do
    subject { Font.default_outline }

    describe 'initial value' do
      let(:value) { true }
      it 'is the expected value' do
        is_expected.to eq value
      end
    end

    let(:value) { false }
    before :each do
      @original_value = Font.default_outline
    end
    after :each do
      Font.default_outline = @original_value
    end

    it 'stores a value' do
      Font.default_outline = value
      is_expected.to eq value
    end

    it 'affects new instances' do
      Font.default_outline = value
      expect(Font.new.outline).to eq value
    end

    context 'with invalid value' do
      let(:value) { nil }

      it 'does not raise an error' do
        expect { Font.default_outline = value }.not_to raise_error
      end

      it 'stores the value' do
        Font.default_outline = value
        is_expected.to eq value
      end

      it 'applies the truthy value to new instances' do
        Font.default_outline = value
        expect(Font.new.outline).to eq !!value
      end
    end
  end

  describe '.default_color' do
    subject { Font.default_color }

    describe 'initial value' do
      let(:value) { Color.new(255, 255, 255, 255) }
      it 'is the expected value' do
        is_expected.to eq value
      end
    end

    let(:value) { Color.new(25, 50, 75, 100) }
    before :each do
      @original_value = Font.default_color
    end
    after :each do
      Font.default_color = @original_value
    end

    it 'stores a value' do
      Font.default_color = value
      is_expected.to eq value
    end

    it 'affects new instances' do
      Font.default_color = value
      expect(Font.new.color).to eq value
    end

    context 'with invalid value' do
      let(:value) { 'foobar' }

      it 'raises a TypeError' do
        expect { Font.default_color = value }.to raise_error(TypeError)
      end
    end
  end

  describe '.default_out_color' do
    subject { Font.default_out_color }

    describe 'initial value' do
      let(:value) { Color.new(0, 0, 0, 128) }
      it 'is the expected value' do
        is_expected.to eq value
      end
    end

    let(:value) { Color.new(25, 50, 75, 100) }
    before :each do
      @original_value = Font.default_color
    end
    after :each do
      Font.default_color = @original_value
    end

    it 'stores a value' do
      Font.default_color = value
      is_expected.to eq value
    end

    it 'affects new instances' do
      Font.default_color = value
      expect(Font.new.color).to eq value
    end

    context 'with invalid value' do
      let(:value) { 'foobar' }

      it 'raises a TypeError' do
        expect { Font.default_color = value }.to raise_error(TypeError)
      end
    end
  end

  describe '.exist?' do
    subject { Font.exist?(font_name) }

    context 'with non-existent font' do
      let(:font_name) { 'foobar_sfrgss_rspec_nonexistent_font' }
      it 'returns false' do
        is_expected.to be false
      end
    end

    context 'with font in data directory' do
      let(:font_name) { 'sfrgss_rspec_test_font' }
      let(:font_file) { "Fonts/#{font_name}.ttf" }
      before :each do
        Dir.mkdir('Fonts') unless Dir.exist?('Fonts')
        File.write(font_file, 'This is generated by a test.')
      end
      after :each do
        File.delete(font_file)
        Dir.delete('Fonts')
      end

      it 'returns true' do
        is_expected.to be true
      end
    end

    context 'with installed system font' do
      let(:font_name) { 'Arial' }
      it 'returns true' do
        is_expected.to be true
      end
    end
  end

end
