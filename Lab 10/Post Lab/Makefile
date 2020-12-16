CXX = clang++
CXXFLAGS = -Wall -g
AS = nasm
ASFLAGS = -f elf64 -g
OBJECTS = heap.o huffnode.o huffmanenc.o
OBJECTS1 = huffmandec.o huffnode.o
target: encoder decoder
encoder: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o encoder
decoder: $(OBJECTS1)
	$(CXX) $(CXXFLAGS) $(OBJECTS1) -o decoder
clean:
	-rm -f *.o *~
