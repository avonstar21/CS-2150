#ifndef HUFFNODE_H
#define HUFFNODE_H
#include <string>
using namespace std;

class huffnode {
public:
huffnode();
  huffnode(char x, int fre);
  ~huffnode();

  string val;
  int freq;
  huffnode* right;
  huffnode* left;

  friend class heap;
  friend class huffmanenc;
  friend class huffmandec;
};

#endif
