CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall
DEBUG=-g

Makefile: TreeCalc.o TreeCalcTest.o TreeNode.o
	$(CXX) $(DEBUG) TreeCalc.o TreeCalcTest.o TreeNode.o


TreeCalc.o: TreeCalc.cpp TreeCalc.h TreeNode.h
TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h TreeNode.h
TreeNode.o: TreeNode.cpp TreeNode.h

.PHONY: clean
clean:
	-rm -f *.o *~a.out
