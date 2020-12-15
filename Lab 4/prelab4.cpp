#include <iostream>
#include <climits>
#include <cmath>
#include <stdint.h>

using namespace std;
void sizeOfTest(){
  cout<<"Size of int: " << sizeof(int) << endl;
  cout<<"Size of unsigned int: " << sizeof (unsigned int) << endl;
  cout<<"Size of float: " << sizeof (float) << endl;
  cout<<"Size of double: " << sizeof (double) << endl;
  cout<<"Size of char: " << sizeof (char) << endl;
  cout<<"Size of bool: " << sizeof (bool)  << endl;
  cout<<"Size of int*: " << sizeof (int*) << endl;
  cout<<"Size of char*: " << sizeof (char*) << endl;
  cout<<"Size of double*: " << sizeof (double*) << endl;
}

void overflow(){
  cout<< UINT_MAX << " + " << 1 << " = " << UINT_MAX + 1 << endl;
}

void outputBinary(int x){
  string str = "00000000000000000000000000000000";
  long int outie = 0;
  // _int32 output;
  while (x !=0){
    int count = 0;
    int n = x;
    
    while(n>>1 != 0){
      if(n == 1){
	//str += "1";
	break;
      }else{
	n = n>>1;
	count++;
      }
    }
    //if(n>>1 == 0){
    //  str+= "0";
    
    // }
    str = str.substr(0,32 - 1 - count) +"1" + str.substr(32 - count);  
    //cout << count << endl;
    //cout << pow(2,count) << endl;
    x = x - pow(2,count);
    //cout << x << endl;
    //outie += pow(10,count);
    //cout <<"This is outie: " <<outie << endl;
  }
 
  str = str.substr(0,4) + " " + str.substr(4,4) + " " + str.substr(8,4) + " " + str.substr(12,4) + " " + str.substr(16,4) + " " + str.substr(20,4) + " " + str.substr(24,4) + " " + str.substr(28,4) + " ";
  cout<<str<<endl;
}


int main(){
int response;
  cin >> response;
  sizeOfTest();
  overflow();
  outputBinary(response);
 
 return 0;
}

