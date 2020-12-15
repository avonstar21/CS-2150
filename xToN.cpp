#include <iostream>
using namespace std;

int xton(int x, int n){
  if(n == 0)
    return 1;
  if(n == 1)
  return x;
  else
   return  x * xton(x,n-1);
}

int main(){
  int x, n, o;
  cin >> x;
  cin >> n;
  o = xton(x,n);
  cout << o<< endl;
  return 0;
}
