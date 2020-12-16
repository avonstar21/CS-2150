#include "huffnode.h"
#include <string>
using namespace std;
huffnode::huffnode(){
  val = "";
  freq = 0;
  left = NULL;
  right = NULL;
}
huffnode::huffnode(char x, int fre){
  val=x;
  freq = fre;
  left = NULL;
  right = NULL;
}

huffnode::~huffnode(){
  delete left;
  delete right;
  left = NULL;
  right = NULL;
}
