CXX = clang++
CXXFLAGS = -Wall -g
AS = nasm
ASFLAGS = -f elf64 -g
OBJECTS = heap.o huffnode.o huffmanenc.o
a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)
clean:
	-rm -f *.o *~
