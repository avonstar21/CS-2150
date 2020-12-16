// This program is the skeleton code for the lab 10 in-lab.
// It uses C++ streams for the file input,
// and just prints out the data when read in from the file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "huffnode.h"
using namespace std;
void insertCode(huffnode* head, string a, string code);
string decode(string x, huffnode* head);
void printTree(huffnode* head);
// main(): we want to use parameters
int main (int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    huffnode* head = new huffnode();
    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
        //cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;
	insertCode(head,character,prefix);
	//printTree(head);
    }
    //printTree(head);
    //head->left = new huffnode('c',1);
    //head->right->right = new huffnode('b',1);
    //printTree(head);
    //cout << "Everything has been inserted" << endl;
    //cout<< "Head Val: " << head->val << endl;
      // read in the second section of the file: the encoded message
    stringstream sstm;
    string ans = "";
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
	//cout << bits << endl;
        sstm << bits;
	//decoded << decode(bits,head);
	ans.append(decode(bits,head));
	//cout << ans << endl;
    }
    //ans.append("\n");
    string allbits = sstm.str();
    
    // at this point, all the bits are in the 'allbits' string
    // cout << "All the bits: " << allbits << endl;
    cout << ans << endl;
    // close the file before exiting
    file.close();
    return 0;
}

void insertCode(huffnode* node, string a, string code){
   if(code.length() == 1){
    char x = a[0];
    if(code == "0"){
      node->left = new huffnode(x,1);
    }else if(code == "1"){
      node->right = new huffnode(x,1);
    }
  }else{
    //char x = a[0];
    //head = new huffnode();
    if(code.substr(0,1) == "0"){
      if(node->left == NULL){
      node->left = new huffnode();
      code = code.substr(1);
      insertCode(node->left, a, code);
     }else{
     insertCode(node->left,a,code.substr(1));
     }
    }else if(code.substr(0,1) == "1"){
      if(node->right == NULL){
      node->right = new huffnode();
      code = code.substr(1);
      insertCode(node->right, a, code);
      }else{
	insertCode(node->right, a, code.substr(1));
      }
    }
    }
}

string decode(string x, huffnode* head){
  if(x.size()==1){
    if(x == "0"){
      return head->left->val;
    }else{
      return head->right->val;
    }
  }else{
    if(x.substr(0,1) == "0"){
      return decode(x.substr(1), head->left);
    }else{
      return decode(x.substr(1), head->right);
    }
  }

}

void printTree(huffnode* head){
  if(head->left == NULL && head->right == NULL){
    cout << head->val << endl;
  }else if(head->left == NULL && head->right != NULL){
    cout << head->val << "       " << endl;
    printTree(head->right);
  }else if(head->left != NULL && head->right == NULL){
    cout << head->val << "       " << endl;
    printTree(head->left);
  }else{
    cout<< head->val << "       ";
    printTree(head->left);
    printTree(head->right);
  }
}
