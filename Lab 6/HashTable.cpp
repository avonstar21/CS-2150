#include <iostream>
#include <string>
#include "HashTable.h"

using namespace std;
//string holder[5];
int  arrSize;
string* holder;

HashTable::HashTable(int size){
  arrSize = size;
  holder = new string[arrSize];
  
}


bool HashTable::checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int HashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}

int HashTable::hashFunc(string x){
  string m;
  //cout<< "Calling hash func" << endl;
  for(int i = 0; i < x.size(); i++){
    char j = x[i];
    //cout << j << endl;
    int k = (int)j;
    //cout << k << endl;
    //string addMe = "" + k;
    //cout << addMe << endl;
    m += to_string(k);
  }
  m = m.substr(0,8);
  //cout << "to be hashed: " << m << endl;
  int hashMe = stoi(m,nullptr,10);
  return hashMe % arrSize;
}

void HashTable::insert(string x){
  //hash-method
  // cout << x << endl;
  int r = hashFunc(x);
  //cout <<"Hash Value: " << r << endl;
  if(holder[r] == ""){
    //cout<< "I have entered!" << endl;
    // cout<< holder[hashed] << endl;
    holder[r] = x;
    //cout<< holder[hashed] << endl;
    //cout<< x << "has been inserted" << endl;
    // break;
  }else{
    // cout<< "I have entered the else statement!" << endl;
    int h = r;
    int ho = arrSize - 1;
    for(int m = r; m < arrSize; m++){
      // cout<< "entered loop 1" << endl;
      if(holder[m] == ""){
	//cout<< holder[m] << endl;
	holder[m] = x;
	//cout << holder[m] << endl;
	//cout << x << "has been inserted" << endl;
	break;
      }
      if(h == ho){
	//string toInsert[getNextPrime(sizeof(holder))];
	for(int k = 0; k < h; k++){
	  // cout<<"entered loop 2" << endl;
	  if(holder[k] == ""){
	    holder[k] = x;
	    // cout << holder[k] << endl;
	    //cout << x << "has been inserted" << endl;
	    break;
	  }
	  break;
	}
	//cout << x << " was not inserted" << endl;
	//holder = toInsert;
      }
    }
  }
}

bool HashTable::contains(string x){
  int r = hashFunc(x);
  for(int i = r; i < arrSize; i++){
    if(holder[i] == x){
      return true;;
    }/*else if(holder[i] == ""){
      return false;
      }*/
  }
  for(int i = 0; i < r; i++){
    if(holder[i] == x){
      return true;
    }
  }
  return false;
 
}
