#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <map>
#include <iterator>
#include "heap.h"
#include "huffnode.h"

using namespace std;
map<char,int> freq_map;
map<char,string> opcodes;

int main(int argc, char** argv){
  ifstream file(argv[1]);
  char g;
  int count = 0;
  while(file.get(g)){
    if(g >= 32){
    if(freq_map.count(g) > 0){
      freq_map[g]++;
      //cout<<g<<endl;
      count++;
    }else{
      freq_map.insert({g,1});
      // cout<<g<<endl;
      count++;
    }
   }
  }
  file.close();
  //cout<< "count is " << count << endl;
  heap* huffmantree = new heap();
  map<char,int>::iterator it = freq_map.begin();
  while(it != freq_map.end()){
    char in = it->first;
    int frel = it->second;
    //cout << in << ": " << frel << endl;
    huffnode* ans = new huffnode(in,frel);
    huffmantree->insert(ans);
    ++it;
  }
  
  
  while(huffmantree->size() > 1){

    huffnode* insertLeft = huffmantree->deleteMin();
    //cout << insertLeft->val << ": " << insertLeft->freq << endl;
    huffnode* insertRight = huffmantree->deleteMin();
    //cout << insertRight->val << ": " << insertRight->freq << endl;
    huffnode* dummyPoint = new huffnode('n',0);
    dummyPoint->freq = insertLeft->freq + insertRight->freq;
    dummyPoint->left = insertLeft;
    dummyPoint->right = insertRight;
    huffmantree->insert(dummyPoint);
    //huffmantree->print();
  }

  map<char, int>::iterator ops = freq_map.begin();
  while(ops != freq_map.end()){
    huffnode* holder = new huffnode();
    holder->val = ops->first;
    holder->freq = ops->second;
    string prefix = huffmantree->opcode(holder,huffmantree->findMin());
    cout<< ops->first << " " << prefix<< endl;
    opcodes.insert({ops->first,prefix});
    ops++;
  }
  cout<< "-----------------------------------------------------" << endl;
  ifstream ent(argv[1]);
  string encoding = "";
  char x;
  while(ent.get(x)){
    encoding.append(opcodes[x]);
    //cout << opcodes[x] << endl;
    encoding.append(" ");
  }
  cout << encoding << endl;
  cout<< "-----------------------------------------------------" << endl;
  cout<< "There are a total of " << count << " symbols that are encoded." << endl;
  cout << "There are " << freq_map.size() << " distinct symbols used." << endl;
  int bit_count = count * 8;
  cout << "There were " << bit_count << " bits in the original file." << endl;
  map<char, int>::iterator compress = freq_map.begin();
  int comp_count = 0;
  while(compress != freq_map.end()){
    int temp = freq_map[compress->first] * opcodes[compress->first].length();
    comp_count += temp;
    compress++;
  }
  cout << "There were " << comp_count << " bits in the compressed file." << endl;
  float comp_r =(float)bit_count/(float)comp_count;
  cout << "This gives a compression ratio of " << comp_r << endl;
  float cost = (float)comp_count/(float)count;
  cout << "The cost of the Huffman tree is " << cost << " bits per character." << endl;
  return 0;
}
