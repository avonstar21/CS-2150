CXX = clang++
CXXFLAGS = -Wall -g
AS = nasm
ASFLAGS = -f elf64 -g
OBJECTS = topological.o
a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)
	doxygen
