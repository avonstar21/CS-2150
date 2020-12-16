#include <iostream>
#include <fstream>
#include <cstdlib>
#include <queue>
#include <map>
#include "board.h"
using namespace std;
/**
 *@author Avni Garg
 *@par solving the puzzle
 *check inversions first and only if inversion number is even do we bother trying to solve. 
*/
int main(){
  int puzzleBoard[3][3];
  
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      cin >> puzzleBoard[i][j];
    }
  }
  board start = board(puzzleBoard);
  int checker = start.numberInversions();
  //cout << "Number of Inversions: " << checker << endl;
  if(checker%2 == 1){
    cout << "IMPOSSIBLE" << endl;
    exit(0);
  }else{

  }
}

