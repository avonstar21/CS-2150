// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include "heap.h"
#include "huffnode.h"
using namespace std;

// default constructor
heap::heap() : heap_size(0) {
   heap1.push_back(new huffnode());

    //huffnode node = new huffnode();
}

// builds a heap from an unsorted vector
heap::heap(vector<huffnode*> vec) : heap_size(vec.size()) {
    heap1 = vec;
    heap1.push_back(heap1[0]);
    heap1[0] = new huffnode();
    for (int i = heap_size/2; i > 0; i--) {
        percolateDown(i);
    }
}

// the destructor doesn't need to do much
heap::~heap() {
}

void heap::insert(huffnode* x) {//figure out the insert algorithm later
  
      // a vector push_back will resize as necessary
    heap1.push_back(x);
    // move it up into the right position
    percolateUp(++heap_size);
}
bool heap::contains_val(huffnode* target, huffnode* head){
  if(head->left == NULL && head->right == NULL){
    if(head->val == target->val){
      return true;
    }else{
      return false;
    }
  }else if(head->val == target->val){
    return true;
  }else{
    return contains_val(target,head->left) || contains_val(target,head->right);
  }
}
string heap:: opcode(huffnode* target, huffnode* x){
  if(x->left == NULL && x->right == NULL){
    if(target->val == x->val){
      return "";
    }
  }else{
    if(target->val == x->val){
      return "0"; 
    }
    else if(contains_val(target,x->right)){
	return  "1" + opcode(target, x->right);
	//return entry;
      }else if(contains_val(target,x->left)){
	return "0" + opcode(target,x->left);
	//return entry;
      }
      return "na";
    }
}

void heap::percolateUp(int hole) {
    // get the value just inserted
  // huffnode y = heap[hole];
  huffnode* x = heap1[hole];
    
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x->freq < heap1[hole/2]->freq); hole /= 2) {
        heap1[hole] = heap1[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    heap1[hole] = x;
}

huffnode* heap::deleteMin() {
    // make sure the heap is not empty
    if (heap_size == 0) {
        throw "deleteMin() called on empty heap";
    }

    // save the value to be returned
    huffnode* ret = heap1[1];
    // move the last inserted position into the root
    heap1[1] = heap1[heap_size--];
    // make sure the vector knows that there is one less element
    heap1.pop_back();
    // percolate the root down to the proper position
    if (!isEmpty()) {
        percolateDown(1);
    }
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
    huffnode* x = heap1[hole];
    // while there is a left child...
    while (hole*2 <= heap_size) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ((child+1 <= heap_size) && (heap1[child+1]->freq < heap1[child]->freq)) {
            child++;
        }
        // if the child is greater than the node...
        if (x->freq > heap1[child]->freq) {
            heap1[hole] = heap1[child]; // move child up
            hole = child;             // move hole down
        } else {
            break;
        }
    }
    // correct position found!  insert at that spot
    heap1[hole] = x;
}

huffnode* heap::findMin() {
    if (heap_size == 0) {
        throw "findMin() called on empty heap";
    }
    return heap1[1];
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
    heap1.resize(1);
}

bool heap::isEmpty() {
    return heap_size == 0;
}

void heap::print() {
    cout << "(" << heap1[0]->val << ") ";
    for (int i = 1; i <= heap_size; i++) {
        cout << heap1[i]->val << " ";
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if (isPow2) {
            cout << endl << "\t";
        }
    }
    cout << endl;
}
