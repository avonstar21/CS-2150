#include "board.h"
#include <iostream>

using namespace std;

board::board(int x[3][3]){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      ans[i][j] = x[i][j];
    }
  }
  //progression.push_back(ans);
}

int board::numberInversions(){
  int retVal = 0;
  for(int r = 0; r < 2; r++){
    for(int c = r + 1; c < 3; c++){
      if(ans[c][r] > 0 && ans[c][r] > ans[r][c]){
	retVal++;
      }
    }
  }
  return retVal;
}
/*
void generateNeighbors(){
  progression.push_back(rowUp());
  progression.push_back(rowDown());
  progression.push_back(colLeft());
  progression.push_back(colRight());
}

int[3][3] rowUp(){
  int temp[3][3];
  int x;
  int y;
  for(int r = 0; r < 3; r++){
    for(int c = 0; c < 3; c++){
      temp[r][c] = ans[r][c];
      if(temp[r][c] == 0){
	x = r;
	y = c;
      }
    }
  }

  if(x > 0){
    int holder = temp[x-1][y];
    temp[x-1][y] = 0;
    temp[x][y] = holder;
    return temp;
  }
  return NULL;
}

int[3][3] rowDown(){
  int temp[3][3];
  int x;
  int y;
  for(int r = 0; r < 3; r++){
    for(int c = 0; c < 3; c++){
      temp[r][c] = ans[r][c];
      if(temp[r][c] == 0){
	x = r;
	y = c;
      }
    }
  }

  if(x < 2){
    int holder = temp[x+1][y];
    temp[x+1][y] = 0;
    temp[x][y] = holder;
    return temp;
  }
  return NULL;
}

int[3][3] colLeft(){
  int temp[3][3];
  int x;
  int y;
  for(int r = 0; r < 3; r++){
    for(int c = 0; c < 3; c++){
      temp[r][c] = ans[r][c];
      if(temp[r][c] == 0){
	x = r;
	y = c;
      }
    }
  }

  if(y > 0){
    int holder = temp[x][y - 1];
    temp[x][y-1] = 0;
    temp[x][y] = holder;
    return temp;
  }
  return NULL;
}

int[3][3] colRight(){
  int temp[3][3];
  int x;
  int y;
  for(int r = 0; r < 3; r++){
    for(int c = 0; c < 3; c++){
      temp[r][c] = ans[r][c];
      if(temp[r][c] == 0){
	x = r;
	y = c;
      }
    }
  }

  if(y < 2){
    int holder = temp[x][y + 1];
    temp[x][y + 1] = 0;
    temp[x][y] = holder;
    return temp;
  }
  return NULL;
}
*/
