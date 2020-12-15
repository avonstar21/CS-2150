#include <iostream>
#include "List.h"
using namespace std;
class ListItr;
class ListNode;
List::List() {
  count = 0;
  head = new ListNode();
  tail = new ListNode();
  head->next = tail;
  tail->previous = head;
  
}

List::List(const List& source){
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

List::~List(){
  makeEmpty();
  //delete head;
  //delete tail;
}

List& List::operator=(const List& source){
  if(this == &source){
    return *this;
  }else{
    makeEmpty();

    ListItr iter(source.head->next);
    while(!iter.isPastEnd()){
      insertAtTail(iter.retrieve());
      iter.moveForward();
    }
  }
  return *this;
}

bool List::isEmpty() const{
  if(head->next == tail && tail->previous == head){
    return true;
  }
  return false;
}

void List::makeEmpty(){
  /*ListItr point = last();
  while(!point.isPastBeginning()){
    point.moveBackward();
    delete(point.current->next);}*/
  while(head != NULL){
  ListNode *pointTo = head->next;
  delete(head);
  head = pointTo;
  }
  
}

ListItr List::first() { //need for prelab
  ListItr iter(head);
  iter.moveForward();
  return iter;
}

ListItr List::last() { 
  ListItr iter(tail);
  iter.moveBackward();
  return iter;
}

void List::insertAfter(int x, ListItr position){
  ListNode *toInsert = new ListNode();
  toInsert->value = x;
  toInsert->previous = position.current;
  toInsert->next = position.current->next;
  position.current->next->previous = toInsert;
  position.current->next = toInsert;
  count++;
 
}

void List::insertBefore(int x, ListItr position){
  ListNode *toInsert = new ListNode();
  toInsert->value = x;
  toInsert->next = position.current;
  toInsert->previous = position.current->previous;
  position.current->previous->next = toInsert;
  position.current->previous = toInsert;
  count++;
 
}

void List::insertAtTail(int x){ //need for prelab
  ListNode *toInsert = new ListNode();
  //cout<<x<<"Inserting a value";
  toInsert->value = x;
  //cout<<toInsert->value<<" is being inserted "<<endl;
  toInsert->previous = tail->previous;
  tail->previous->next = toInsert;
  //cout<<toInsert->previous<<"  PREVIOUS";
  toInsert->next = tail;
  //cout<<toInsert->next<< "    NEXT";
  tail->previous = toInsert;
  // tail->next = NULL;
  count++;
  
}

ListItr List::find(int x){
  ListItr iter = first();
  while(!iter.isPastEnd()){
    if(iter.retrieve() == x){
      return iter;
    }else{
      iter.moveForward();
    }
  }
  return iter;
}

void List::remove(int x){
  ListItr iter = find(x);
  
  iter.current->previous->next = iter.current->next;
  iter.current->next->previous = iter.current->previous;
  delete(iter.current);
  count--;
  
}

int List::size() const { //need for prelab
  return count;
}

void printList(List& source, bool forward){
  
  //cout<<forward;
  // cout<<iter.retrieve();
  if(forward){ //print forward
    ListItr iter = source.first();
    // cout<<"Value of Forward: "<<forward;
    //cout<<"Entered!";
    //cout<<"Value of iter.isPastEnd: "<<iter.isPastEnd();
    while(!iter.isPastEnd()){
      //cout<<"a"<<endl;
      //cout<<"entered while loop";
      cout<<iter.retrieve()<<" ";
      iter.moveForward();
      
   }
  }
  if(!forward){
    ListItr iter = source.last();
   while(!iter.isPastBeginning()){
   cout<<iter.retrieve()<<" ";
   iter.moveBackward();
 }
  }
}


