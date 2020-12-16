#include <iostream>
#include "timer.h"
#include <cstdlib>

using namespace std;
extern "C" int threexplusone(int x);

int main(){
  int x;
  int n;
  int ans;
  timer t;
  double timeTaken;
  cout << "Enter a number: ";
  cin >> x;
  cout << "Enter iterations of subroutine: ";
  cin >> n;
  ans = threexplusone(x);
  cout << "Iterations: " << ans << endl;
  /* t.start();
  for(int i = 0; i < n; i++){
    threexplusone(x);
  }
  t.stop();
  timeTaken = t.getTime();
  */
  // cout << "time: " << timeTaken << endl;
   return 0;
}
