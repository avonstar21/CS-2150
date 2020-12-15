#include <iostream>
//#include <fstream>
#include <string>
//#include <vector>
#include "postfixCalculator.h"
#include "StackNode.h"
#include "Stack.h"
using namespace std;
int main(){
  string response;
  int ans = 0;
  string toCalc;
  postfixCalculator myCalc;
  //vector<int> cont;
  while(cin >> response){
    //ans = myCalc.calculate(response);
    myCalc.calculate(response);
    //cout<<ans<< endl;
    //cout<< "entering loop" << endl;
    //cout<< myCalc.getTop() << endl;
  }
  // cout << ans << endl;
  //cout<<ans << endl;
  // cout<< "am i getting here?" << endl;
  cout<< myCalc.getTop() << endl;
  //cout<< "did i make it here?" << endl;
  return 0;
  
}
