#include <iostream>
#include "Stack.h"
#include "StackNode.h"
using namespace std;

Stack::Stack(){
  count = 0;
  head = new StackNode();
  tail = new StackNode();
  head->next = tail;
  tail->previous = head;
}

bool Stack::empty() const{
  if(head->next == tail && tail->previous == head){
    return true;
  }
  return false;
}

void Stack::push(int e){
  StackNode *toPush = new StackNode();
  toPush->value = e;
  toPush->previous = tail->previous;
  tail->previous->next = toPush;
  toPush->next = tail;
  tail->previous = toPush;
  count++;
}

void Stack::pop(){
  tail->previous = tail->previous->previous;
  tail->previous->next = tail;
  count--;
}

int Stack::top() const{
  return tail->previous->value;
}
