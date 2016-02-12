require_relative '../spec_helper'

RSpec.describe Table do

  context '2D' do
    let(:xsize) { 3 }
    let(:ysize) { 4 }
    subject(:table) { Table.new(xsize, ysize) }

    describe '#new' do
      context 'with invalid xsize' do
        it 'raises a TypeError' do
          expect { Table.new(nil, ysize) }.to raise_error(TypeError)
        end
      end

      context 'with invalid ysize' do
        it 'raises a TypeError' do
          expect { Table.new(xsize, nil) }.to raise_error(TypeError)
        end
      end

      context 'with 0 xsize' do
        let(:xsize) { 0 }

        it 'does not raise an error' do
          expect { Table.new(xsize, ysize) }.not_to raise_error
        end

        describe '#xsize' do
          subject { table.xsize }
          it 'is 0' do
            is_expected.to eq 0
          end
        end

        describe '#ysize' do
          subject { table.ysize }
          it 'is the expected value' do
            is_expected.to eq ysize
          end
        end
      end

      context 'with 0 ysize' do
        let(:ysize) { 0 }

        it 'does not raise an error' do
          expect { Table.new(xsize, ysize) }.not_to raise_error
        end

        describe '#xsize' do
          subject { table.xsize }
          it 'is the expected value' do
            is_expected.to eq xsize
          end
        end

        describe '#ysize' do
          subject { table.ysize }
          it 'is 0' do
            is_expected.to eq 0
          end
        end
      end

      context 'with negative xsize' do
        let(:xsize) { -5 }

        it 'does not raise an error' do
          expect { Table.new(xsize, ysize) }.not_to raise_error
        end

        describe '#xsize' do
          subject { table.xsize }
          it 'is 0' do
            is_expected.to eq 0
          end
        end

        describe '#ysize' do
          subject { table.ysize }
          it 'is the expected value' do
            is_expected.to eq ysize
          end
        end
      end

      context 'with negative ysize' do
        let(:ysize) { -5 }

        it 'does not raise an error' do
          expect { Table.new(xsize, ysize) }.not_to raise_error
        end

        describe '#xsize' do
          subject { table.xsize }
          it 'is the expected value' do
            is_expected.to eq xsize
          end
        end

        describe '#ysize' do
          subject { table.ysize }
          it 'is 0' do
            is_expected.to eq 0
          end
        end
      end
    end

    describe 'initial contents' do
      it 'is zeroed' do
        (0...xsize).each do |x|
          (0...ysize).each do |y|
            expect(table[x, y]).to eq 0
          end
        end
      end
    end

    describe '#xsize' do
      subject { table.xsize }
      it 'is the expected value' do
        is_expected.to eq xsize
      end
    end

    describe '#ysize' do
      subject { table.ysize }
      it 'is the expected value' do
        is_expected.to eq ysize
      end
    end

    describe '#zsize' do
      subject { table.zsize }
      it 'is 1' do
        is_expected.to eq 1
      end
    end

    describe '#[]' do
      context 'with negative x' do
        it 'returns nil' do
          expect(table[-3, 0]).to be_nil
        end
      end
      context 'with negative y' do
        it 'returns nil' do
          expect(table[0, -7]).to be_nil
        end
      end

      context 'treat as 1D' do
        it 'raises an ArgumentError' do
          expect { table[0] }.to raise_error(ArgumentError)
        end
      end

      context 'treat as 3D' do
        it 'raises an ArgumentError' do
          expect { table[0, 0, 0] }.to raise_error(ArgumentError)
        end
      end
    end

    describe '#[]=' do
      it 'stores a value' do
        table[1, 2] = 5
        expect(table[1, 2]).to eq 5
      end

      context 'with negative x' do
        it 'does not raise an error' do
          expect { table[-3, 0] = 5 }.to_not raise_error
        end

        it 'does not change the contents' do
          table[-3, 0] = 5
          (0...xsize).each do |x|
            (0...ysize).each do |y|
              expect(table[x, y]).to eq 0
            end
          end
        end
      end

      context 'with negative y' do
        it 'does not raise an error' do
          expect { table[0, -7] = 5 }.to_not raise_error
        end

        it 'does not change the contents' do
          table[0, -7] = 5
          (0...xsize).each do |x|
            (0...ysize).each do |y|
              expect(table[x, y]).to eq 0
            end
          end
        end
      end

      context 'treat as 1D' do
        it 'raises an ArgumentError' do
          expect { table[0] = 5 }.to raise_error(ArgumentError)
        end
      end

      context 'treat as 3D' do
        it 'raises an ArgumentError' do
          expect { table[0, 0, 0] = 5 }.to raise_error(ArgumentError)
        end
      end
    end

    describe '#resize' do
      before :each do
        (0...xsize).each do |x|
          (0...ysize).each do |y|
            table[x, y] = (x + 1) * (y + 2) * 3
          end
        end
      end

      it 'returns itself' do
        expect(table.resize(table.xsize, table.ysize)).to be table
      end

      context 'to 1D' do
        context 'larger xsize' do
          subject(:result) { table.resize(xsize + 3) }

          it 'retains existing values' do
            (0...xsize).each do |x|
              expect(result[x]).to eq((x + 1) * 6)
            end
          end

          it 'fills with 0' do
            (xsize...(xsize + 3)).each do |x|
              expect(result[x]).to eq 0
            end
          end
        end

        context 'smaller xsize' do
          subject(:result) { table.resize(xsize - 2) }

          it 'retains existing values' do
            (0...(xsize - 2)).each do |x|
              expect(result[x]).to eq((x + 1) * 6)
            end
          end
        end

        context 'with 0 xsize' do
          subject(:result) { table.resize(0) }

          it 'does not raise an error' do
            expect { result }.to_not raise_error
          end

          describe '#xsize' do
            subject { result.xsize }

            it 'is 0' do
              is_expected.to eq 0
            end
          end
        end

        context 'with negative xsize' do
          subject(:result) { table.resize(-5) }

          it 'does not raise an error' do
            expect { result }.to_not raise_error
          end

          describe '#xsize' do
            subject { result.xsize }

            it 'is 0' do
              is_expected.to eq 0
            end
          end
        end
      end

      context 'to 2D' do
        context 'larger xsize, larger ysize' do
          subject(:result) { table.resize(xsize + 3, ysize + 5) }

          it 'retains existing values' do
            (0...xsize).each do |x|
              (0...ysize).each do |y|
                expect(result[x, y]).to eq((x + 1) * (y + 2) * 3)
              end
            end
          end

          it 'fills with 0' do
            (0...(xsize + 3)).each do |x|
              (0...(ysize + 5)).each do |y|
                if x >= xsize || y >= ysize
                  expect(result[x, y]).to eq 0
                end
              end
            end
          end
        end

        context 'larger xsize, smaller ysize' do
          subject(:result) { table.resize(xsize + 3, ysize - 2) }

          it 'retains existing values' do
            (0...xsize).each do |x|
              (0...(ysize - 2)).each do |y|
                expect(result[x, y]).to eq((x + 1) * (y + 2) * 3)
              end
            end
          end

          it 'fills with 0' do
            (0...(xsize + 3)).each do |x|
              (0...(ysize - 2)).each do |y|
                if x >= xsize
                  expect(result[x, y]).to eq 0
                end
              end
            end
          end
        end

        context 'smaller xsize, smaller ysize' do
          subject(:result) { table.resize(xsize - 2, ysize - 2) }

          it 'retains existing values' do
            (0...(xsize - 2)).each do |x|
              (0...(ysize - 2)).each do |y|
                expect(result[x, y]).to eq((x + 1) * (y + 2) * 3)
              end
            end
          end
        end

        context 'smaller xsize, larger ysize' do
          subject(:result) { table.resize(xsize - 2, ysize + 3) }

          it 'retains existing values' do
            (0...(xsize - 2)).each do |x|
              (0...ysize).each do |y|
                expect(result[x, y]).to eq((x + 1) * (y + 2) * 3)
              end
            end
          end

          it 'fills with 0' do
            (0...(ysize - 2)).each do |y|
              (0...(xsize + 3)).each do |x|
                if y >= ysize
                  expect(result[x, y]).to eq 0
                end
              end
            end
          end
        end

        context 'with 0 xsize' do
          subject(:result) { table.resize(0, 5) }

          it 'does not raise an error' do
            expect { result }.to_not raise_error
          end

          describe '#xsize' do
            subject { result.xsize }

            it 'is 0' do
              is_expected.to eq 0
            end
          end

          describe '#ysize' do
            subject { result.ysize }

            it 'is the expected value' do
              is_expected.to eq 5
            end
          end
        end

        context 'with 0 ysize' do
          subject(:result) { table.resize(5, 0) }

          it 'does not raise an error' do
            expect { result }.to_not raise_error
          end

          describe '#xsize' do
            subject { result.xsize }

            it 'is the expected value' do
              is_expected.to eq 5
            end
          end

          describe '#ysize' do
            subject { result.ysize }

            it 'is 0' do
              is_expected.to eq 0
            end
          end
        end

        context 'with negative xsize' do
          subject(:result) { table.resize(-5, 5) }

          it 'does not raise an error' do
            expect { result }.to_not raise_error
          end

          describe '#xsize' do
            subject { result.xsize }

            it 'is 0' do
              is_expected.to eq 0
            end
          end

          describe '#ysize' do
            subject { result.ysize }

            it 'is the expected value' do
              is_expected.to eq 5
            end
          end
        end

        context 'with negative ysize' do
          subject(:result) { table.resize(5, -5) }

          it 'does not raise an error' do
            expect { result }.to_not raise_error
          end

          describe '#xsize' do
            subject { result.xsize }

            it 'is the expected value' do
              is_expected.to eq 5
            end
          end

          describe '#ysize' do
            subject { result.ysize }

            it 'is 0' do
              is_expected.to eq 0
            end
          end
        end
      end

      context 'to 3D' do
        context 'larger xsize, larger ysize' do
          subject(:result) { table.resize(xsize + 3, ysize + 5, 2) }

          it 'retains existing values' do
            (0...xsize).each do |x|
              (0...ysize).each do |y|
                expect(result[x, y, 0]).to eq((x + 1) * (y + 2) * 3)
              end
            end
          end

          it 'fills with 0' do
            (0...2).each do |z|
              (0...(ysize + 5)).each do |y|
                (0...(xsize + 3)).each do |x|
                  if z != 0 || y >= ysize || x >= xsize
                    expect(result[x, y, z]).to eq 0
                  end
                end
              end
            end
          end
        end

        context 'larger xsize, smaller ysize' do
          subject(:result) { table.resize(xsize + 3, ysize - 2, 2) }

          it 'retains existing values' do
            (0...xsize).each do |x|
              (0...(ysize - 2)).each do |y|
                expect(result[x, y, 0]).to eq((x + 1) * (y + 2) * 3)
              end
            end
          end

          it 'fills with 0' do
            (0...2).each do |z|
              (0...(ysize - 2)).each do |y|
                (0...(xsize + 3)).each do |x|
                  if z != 0 || x >= xsize
                    expect(result[x, y, z]).to eq 0
                  end
                end
              end
            end
          end
        end

        context 'smaller xsize, smaller ysize' do
          subject(:result) { table.resize(xsize - 3, ysize - 2, 2) }

          it 'retains existing values' do
            (0...xsize).each do |x|
              (0...(ysize - 2)).each do |y|
                expect(result[x, y, 0]).to eq((x + 1) * (y + 2) * 3)
              end
            end
          end

          it 'fills with 0' do
            (1...2).each do |z|
              (0...(ysize - 2)).each do |y|
                (0...(xsize - 3)).each do |x|
                  expect(result[x, y, z]).to eq 0
                end
              end
            end
          end
        end

        context 'smaller xsize, larger ysize' do
          subject(:result) { table.resize(xsize - 2, ysize + 3, 2) }

          it 'retains existing values' do
            (0...(xsize - 2)).each do |x|
              (0...ysize).each do |y|
                expect(result[x, y, 0]).to eq((x + 1) * (y + 2) * 3)
              end
            end
          end

          it 'fills with 0' do
            (0...2).each do |z|
              (0...(ysize + 3)).each do |y|
                (0...(xsize - 2)).each do |x|
                  if z != 0 || y >= ysize
                    expect(result[x, y, z]).to eq 0
                  end
                end
              end
            end
          end
        end

        context 'with 0 xsize' do
          subject(:result) { table.resize(0, 5, 7) }

          it 'does not raise an error' do
            expect { result }.to_not raise_error
          end

          describe '#xsize' do
            subject { result.xsize }

            it 'is 0' do
              is_expected.to eq 0
            end
          end

          describe '#ysize' do
            subject { result.ysize }

            it 'is the expected value' do
              is_expected.to eq 5
            end
          end

          describe '#zsize' do
            subject { result.zsize }

            it 'is the expected value' do
              is_expected.to eq 7
            end
          end
        end

        context 'with 0 ysize' do
          subject(:result) { table.resize(5, 0, 7) }

          it 'does not raise an error' do
            expect { result }.to_not raise_error
          end

          describe '#xsize' do
            subject { result.xsize }

            it 'is the expected value' do
              is_expected.to eq 5
            end
          end

          describe '#ysize' do
            subject { result.ysize }

            it 'is 0' do
              is_expected.to eq 0
            end
          end

          describe '#zsize' do
            subject { result.zsize }

            it 'is the expected value' do
              is_expected.to eq 7
            end
          end
        end

        context 'with 0 zsize' do
          subject(:result) { table.resize(5, 7, 0) }

          it 'does not raise an error' do
            expect { result }.to_not raise_error
          end

          describe '#xsize' do
            subject { result.xsize }

            it 'is the expected value' do
              is_expected.to eq 5
            end
          end

          describe '#ysize' do
            subject { result.ysize }

            it 'is the expected value' do
              is_expected.to eq 7
            end
          end

          describe '#zsize' do
            subject { result.zsize }

            it 'is 0' do
              is_expected.to eq 0
            end
          end
        end

        context 'with negative xsize' do
          subject(:result) { table.resize(-5, 5, 7) }

          it 'does not raise an error' do
            expect { result }.to_not raise_error
          end

          describe '#xsize' do
            subject { result.xsize }

            it 'is 0' do
              is_expected.to eq 0
            end
          end

          describe '#ysize' do
            subject { result.ysize }

            it 'is the expected value' do
              is_expected.to eq 5
            end
          end

          describe '#zsize' do
            subject { result.zsize }

            it 'is the expected value' do
              is_expected.to eq 7
            end
          end
        end

        context 'with negative ysize' do
          subject(:result) { table.resize(5, -5, 7) }

          it 'does not raise an error' do
            expect { result }.to_not raise_error
          end

          describe '#xsize' do
            subject { result.xsize }

            it 'is the expected value' do
              is_expected.to eq 5
            end
          end

          describe '#ysize' do
            subject { result.ysize }

            it 'is 0' do
              is_expected.to eq 0
            end
          end

          describe '#zsize' do
            subject { result.zsize }

            it 'is the expected value' do
              is_expected.to eq 7
            end
          end
        end

        context 'with negative zsize' do
          subject(:result) { table.resize(5, 7, -5) }

          it 'does not raise an error' do
            expect { result }.to_not raise_error
          end

          describe '#xsize' do
            subject { result.xsize }

            it 'is the expected value' do
              is_expected.to eq 5
            end
          end

          describe '#ysize' do
            subject { result.ysize }

            it 'is the expected value' do
              is_expected.to eq 7
            end
          end

          describe '#zsize' do
            subject { result.zsize }

            it 'is 0' do
              is_expected.to eq 0
            end
          end
        end
      end
    end

    describe '#_dump' do
      let(:values) { [[5, 25, 45], [10, 30, 50], [15, 35, 55], [20, 40, 60]] }
      let(:bytes)  { [2, 0, 0, 0, 3, 0, 0, 0, 4, 0, 0, 0, 1, 0, 0, 0, 12, 0, 0, 0, 5, 0, 25, 0, 45, 0, 10, 0, 30, 0, 50, 0, 15, 0, 35, 0, 55, 0, 20, 0, 40, 0, 60, 0] }
      let(:table) do
        t = Table.new(values.first.length, values.length)
        values.each.with_index do |row, y|
          row.each_index do |x|
            t[x, y] = values[y][x]
          end
        end
        t
      end
      subject { table._dump(10).unpack('C*') }

      it 'generates expected result' do
        is_expected.to eq bytes
      end
    end

    describe '._load' do
      let(:values) { [[5, 25, 45], [10, 30, 50], [15, 35, 55], [20, 40, 60]] }
      let(:bytes)  { [2, 0, 0, 0, 3, 0, 0, 0, 4, 0, 0, 0, 1, 0, 0, 0, 12, 0, 0, 0, 5, 0, 25, 0, 45, 0, 10, 0, 30, 0, 50, 0, 15, 0, 35, 0, 55, 0, 20, 0, 40, 0, 60, 0] }
      subject(:table) { Table._load(bytes.pack('C*')) }

      it 'contains the expected values' do
        values.each.with_index do |row, y|
          row.each_index do |x|
            expect(table[x, y]).to eq values[y][x]
          end
        end
      end
    end
  end

end
