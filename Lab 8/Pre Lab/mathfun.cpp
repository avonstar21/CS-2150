#include <iostream>
#include <cstdlib>
using namespace std;

extern "C" int product(int, int);
extern "C" int power(int,int);

int main() {
  int one,two;
  cout<< "Enter integer 1:" << endl;
  cin >> one;
  cout<< "Enter integer 2:" << endl;
  cin >> two;

  int ans1 = product(one,two);
  cout<< "Product: " << ans1 << endl;

  int ans2 = power(one,two);
  cout << "Power: " << ans2 << endl;

}
