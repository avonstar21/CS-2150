#include <iostream>
#include <fstream>
#include <string>
#include "HashTable.h"
#include "timer.h"
#include <unordered_set>

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

bool readInGrid(string filename, int& rows, int& cols);
string getWordInGrid(int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);

int main(int argc, char **argv){
  timer t;
  //t.start();
  string gridFilename = argv[2];
  string dictFilename = argv[1];
  int wordCount = 0;
  //HashTable dict;
  ifstream toRead;
  string word;
  int arrSize = 0;
  toRead.open(dictFilename);
  while(getline(toRead,word)){
    // dict.insert(word);
    arrSize++;
  }
  toRead.close();
  HashTable dict(arrSize);
  toRead.open(dictFilename);
  //getline(toRead,word);
  //dict.insert(word);
  while(getline(toRead,word)){
    dict.insert(word);
  }
  toRead.close();
  //ifstream gridRead;
  //gridRead.open(gridFilename);
  int rows = 0;
  int columns = 0;
  bool x = readInGrid(gridFilename, rows, columns);
  t.start();
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < columns; j++){
      for(int dir = 0; dir < 8; dir++){
	for(int len = 3; len <= 22; len++){
	  string ans = getWordInGrid(i,j,dir,len,MAXROWS,MAXCOLS);
	  if(ans.length()>= 3 && dict.contains(ans) == true){
	  //wordCount++;
	  if(dir == 0){
	    cout<< "N (" << i << ", " << j << "):        " << ans << endl;
	     wordCount++;
	    break;
	    //wordCount++;
	  }else if(dir == 1){
	    cout<< "NE (" << i << ", " << j << "):        " << ans << endl;
	    wordCount++;
	    break;
	    wordCount++;
	  }else if(dir == 2){
	    cout<< "E (" << i << ", " << j << "):        " << ans << endl;
	    wordCount++;
	    break;
	    //wordCount++;
	  }else if(dir == 3){
	    cout<< "SE (" << i << ", " << j << "):        " << ans << endl;
	    wordCount++;
	    break;
	    //wordCount++;
	  }else if(dir == 4){
	    cout<< "S (" << i << ", " << j << "):        " << ans << endl;
	    wordCount++;
	    break;
	    //wordCount++;
	  }else if(dir == 5){
	    cout<< "SW (" << i << ", " << j << "):        " << ans << endl;
	    wordCount++;
	    break;
	    //wordCount++;
	  }else if(dir == 6){
	    cout<< "W (" << i << ", " << j << "):        " << ans << endl;
	    wordCount++;
	    break;
	    // wordCount++;
	  }else if(dir == 7){
	    cout<< "NW (" << i << ", " << j << "):        " << ans << endl;
	    wordCount++;
	    break;
	    //wordCount++;
	  }
	  //wordCount++;
	}
	}
      }
    }
  }
  cout << wordCount <<" words found" << endl;
  t.stop();
  //int timeMe = t.getTime() * 1000;
  //cout<< timeMe << endl;
  return 0;
}

bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;

    // then the columns
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
            //cout << grid[r][c];
        }
        //cout << endl;
    }
    return true;
}

string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}
