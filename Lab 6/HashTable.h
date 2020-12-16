#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>

using namespace std;

class HashTable{
 public:
  HashTable(int size);
  void insert(string x);
  bool contains(string x);
  int hashFunc(string x);

 private:
  bool checkprime(unsigned int p);
  int getNextPrime(unsigned int n);

  //string holder[];

  friend class wordPuzzle;
};

#endif
