CXX = clang++
CXXFLAGS = -Wall -g -O2
AS = nasm
ASFLAGS = -f elf64 -g
OBJECTS = traveling.o middleearth.o
a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)
	doxygen
