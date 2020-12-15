#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "StackNode.h"

using namespace std;

class Stack{
 public:
  Stack();
  void push(int e);
  void pop();
  int top() const;
  bool empty() const;

 private:
  StackNode* head;
  StackNode* tail;
  int count;
  friend class postfixCalculator;
  friend class testPostfixCalculator;

};

#endif
