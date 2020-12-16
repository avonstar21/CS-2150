CXX = clang++
CXXFLAGS = -Wall -g
AS = nasm
ASFLAGS = -f elf64 -g
OBJECTS = binarySearch.o testBinarySearch.o timer.o
a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)
clean:
	-rm -f *.o *~
