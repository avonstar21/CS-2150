#include <iostream>
#include "ListItr.h"
using namespace std;
class List;
class ListNode;
ListItr::ListItr(){
  current = new ListNode();
}

ListItr::ListItr(ListNode* theNode){
  current = theNode;
}

bool ListItr::isPastEnd() const{
  if(current->next == NULL){
    return true;
  }
  return false;
}

bool ListItr::isPastBeginning() const{
  if(current->previous == NULL){
    return true;
  }
  return false;
}

void ListItr::moveForward(){
  if(!isPastEnd()){
    current = current->next;
    
  }

}

void ListItr::moveBackward(){
  if(!isPastBeginning()){
    current = current->previous;
  }
}

int ListItr::retrieve() const{
  //cout<<current->value<<endl;
  //cout<< current->value;
  return current->value;
  //return current->previous;
  //return current->next;
}


