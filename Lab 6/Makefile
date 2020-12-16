XX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG=-g

Makefile: HashTable.o timer.o wordPuzzle.o
	$(CXX) $(DEBUG) HashTable.o timer.o wordPuzzle.o

HashTable.o: HashTable.cpp HashTable.h
timer.o: timer.cpp timer.h
wordPuzzle.o: wordPuzzle.cpp HashTable.h

.PHONY: clean
clean:
	 -rm -f *.o *~a.out
