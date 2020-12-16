// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "huffnode.h"
using namespace std;

class heap{
public:
    heap();
    heap(vector<huffnode*> vec);
    ~heap();

    void insert(huffnode* x);
    huffnode* findMin();
    huffnode* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();
    string opcode(huffnode* target, huffnode* x);
    bool contains_val(huffnode* target, huffnode* head);

private:
    vector<huffnode*> heap1;
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);
    friend class huffmanenc;
};

#endif
