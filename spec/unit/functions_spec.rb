require_relative '../spec_helper'

RSpec.describe 'Top-level functions' do

  describe 'rgss_main' do
    subject { rgss_main { 'foobar' } }

    it 'returns nil' do
      is_expected.to be nil
    end

    it 'yields once' do
      expect { |b| rgss_main(&b) }.to yield_control.at_most(1).times
    end

    context 'when no block is given' do
      it 'raises an error' do
        expect { rgss_main }.to raise_error(LocalJumpError)
      end
    end

    context 'when RGSSReset is raised' do
      def reset(count)
        raised = 0
        rgss_main do
          begin
            raise RGSSReset if raised < count
          rescue RGSSReset => e
            raised += 1
            raise e
          end
        end
        raised
      end

      it 're-runs the block' do
        expect(reset(1)).to be 1
      end

      it 'swallows the error' do
        expect { reset(1) }.not_to raise_error
      end

      it 're-runs the block multiple times' do
        expect(reset(3)).to be 3
      end
    end

    context 'when a non-reset exception is raised' do
      it 'propagates the exception' do
        expect { rgss_main { fail 'Whoops' } }.to raise_error(RuntimeError)
      end
    end
  end

  describe 'load_data' do
    let(:filename) { File.expand_path('save-data-test.dat') }
    subject do
      save_data(obj, filename)
      load_data(filename)
    end

    before :each do
      File.unlink(filename) if File.exist?(filename)
    end

    context 'when the file is missing' do
      it 'raises an error' do
        expect { load_data('foobar.dat') }.to raise_error(SystemCallError)
      end
    end

    context 'when object is nil' do
      let(:obj) { nil }
      it 'loads nil' do
        is_expected.to eq obj
      end
    end

    context 'when object is numeric' do
      let(:obj) { 42 }
      it 'loads the same value' do
        is_expected.to eq obj
      end
    end

    context 'when object is an array' do
      let(:obj) { [:foo, :bar, :baz] }
      it 'loads the same value' do
        is_expected.to eq obj
      end
    end

    context 'when object is a hash' do
      let(:obj) { { :foo => 'bar', :baz => 42 } }
      it 'loads the same value' do
        is_expected.to eq obj
      end
    end

    context 'when object is complex' do
      let(:obj) { RPG::Actor.new }

      it 'returns the same type' do
        is_expected.to be_a(RPG::Actor)
      end

      it 'loads the same value' do
        is_expected.to satisfy do |v|
          v.nickname        == obj.nickname        &&
          v.class_id        == obj.class_id        &&
          v.initial_level   == obj.initial_level   &&
          v.max_level       == obj.max_level       &&
          v.character_name  == obj.character_name  &&
          v.character_index == obj.character_index &&
          v.face_name       == obj.face_name       &&
          v.face_index      == obj.face_index      &&
          v.equips          == obj.equips
        end
      end
    end

    after :each do
      File.unlink(filename) if File.exist?(filename)
    end
  end

  describe 'save_data' do
    let(:filename) { File.expand_path('save-data-test.dat') }
    let(:obj) { 'foobar' }
    subject { save_data(obj, filename) }

    before :each do
      File.unlink(filename) if File.exist?(filename)
    end

    it 'returns nil' do
      is_expected.to be nil
    end

    it 'creates a file' do
      subject
      is_expected.to satisfy { File.exist?(filename) }
    end

    after :each do
      File.unlink(filename)
    end
  end

end
