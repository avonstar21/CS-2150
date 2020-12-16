CXX = clang++
CXXFLAGS = -Wall -g -O2
AS = nasm
ASFLAGS = -f elf64 -g
OBJECTS = 8puzzle.o board.o
a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)
	doxygen
