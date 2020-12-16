// Insert your header information here
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor
TreeCalc::TreeCalc() {
  //expressionStack; 
  //TreeNode treeHead = new TreeNode();
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
  cleanTree(expressionStack.top());
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
  //delete(expressionStack)
  if(tree->right == NULL && tree->left == NULL){
    delete(tree);
  }else{
    cleanTree(tree->right);
    cleanTree(tree->left);
    delete(tree);
  }
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
  TreeNode* toPush = new TreeNode(val);
  if(val == "/" || val == "+" || val == "-" || val == "*"){
    //cout<<val;
    toPush->left = expressionStack.top();
    expressionStack.pop();
    toPush->right = expressionStack.top();
    expressionStack.pop();
  }
  expressionStack.push(toPush);
  //cout << expressionStack.top()->value;
}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
    // print the tree in prefix format
  if(tree->right == NULL && tree->left == NULL){
    cout<< tree->value;
  }else{
    cout << tree->value << " ";
    printPrefix(tree->right);
    cout << " ";
    printPrefix(tree->left);
  }
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    // print tree in infix format with appropriate parentheses

  //right - top - left
  if(tree->right == NULL && tree->left == NULL){
    cout<<tree->value;
  }else{
    cout<< "(";
    printInfix(tree->right);
    cout <<" "<< tree->value<< " ";
    printInfix(tree->left);
    cout << ")";
  }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    // print the tree in postfix form
  if(tree->right == NULL && tree->left == NULL){
    cout<<tree->value; 
  }else{
    printPostfix(tree->right);
    cout << " ";
    printPostfix(tree->left);
    cout << " " << tree->value;
  }
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    // Traverse the tree and calculates the result
  if(tree->right == NULL && tree->left == NULL){
    string con = tree->value;
    int x = std::stoi(con);
    return x;
    /* if(tree->value == "1"){
      return 1;
    }else if(tree->value == "2"){
      return 2;
    }else if(tree->value == "3"){
      return 3;
    }else if(tree->value == "4"){
      return 4;
    }else if(tree->value == "5"){
      return 5;
    }else if(tree->value == "6"){
      return 6;
    }else if(tree->value == "7"){
      return 7;
    }else if(tree->value == "8"){
      return 8;
    }else if(tree->value == "9"){
      return 9;
    }else{
      return 0;
      }*/
  }else{
    if(tree->value == "+"){
      return calculate(tree->right)+ calculate(tree->left);
    }else if(tree->value == "-"){
      return calculate(tree->right) - calculate(tree->left);
    }else if(tree->value == "*"){
      return calculate(tree->right) * calculate(tree->right);
    }else{
      return calculate(tree->right)/calculate(tree->left);
    }
  }
    return 0;
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    // call private calculate method here
  return calculate(expressionStack.top());
  return 0;
}
