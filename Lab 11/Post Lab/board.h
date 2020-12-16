#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <queue>
using namespace std;

class board{
 public:
  board(int x[3][3]);
  int numberInversions();
  void printPuzzle();

 private:
  int ans[3][3];
  queue<int[3][3]> progression;
  int endState[3][3] = {{1,2,3},{4,5,6},{7,8,0}};
};

#endif
