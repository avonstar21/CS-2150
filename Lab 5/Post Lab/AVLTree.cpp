#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
  insertHelp(root,x);
}

//insert Helper

void AVLTree::insertHelp(AVLNode*& n, const string& x){
  if(n == NULL){
    n = new AVLNode();
    n->value = x;
    n->height = 0;
    balance(n);
  }else if(x > n->value){
    if(n->right == NULL){
      AVLNode* toInsert = new AVLNode();
      toInsert->value =x;
      n->right = toInsert;
      n->height += 1;
      balance(n);
      printTree();
    }else{
      insertHelp(n->right,x);
      balance(n);
    }
  }else if(x < n->value){
    if(n->left == NULL){
      AVLNode* toInsert = new AVLNode();
      toInsert->value =x;
      n->left = toInsert;
      n->height += 1;
     balance(n);
     printTree();
    }else{
      insertHelp(n->left,x);
      balance(n);
    }
  }
  balance(n);
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  return pathToHelp(root,x);
}

string AVLTree::pathToHelp(AVLNode*const& n, const string& x) const{
if(find(x) == false){
    return "";
  }else{
  if(n->value == x){
    return n->value;
  }else if(n == NULL){
    return " ";
  }else if(x > n->value){
    return n->value +" " + pathToHelp(n->right,x);
  }else if(x < n->value){
    return n->value + " " + pathToHelp(n->left,x);
  }else{
    return n->value;
  }
  }
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  return findHelp(root,x);
}

bool AVLTree::findHelp(AVLNode*const& n, const string& x) const{
if(n->left == NULL && n->right == NULL && n->value != x){
    return false;
  }else if(x > n->value){
  return findHelp(n->right,x);
  }else if(x < n->value){
  return findHelp(n->left,x);
  }else{
    return true;
  }
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
  return numNodesHelp(root);
}

int AVLTree::numNodesHelp(AVLNode*const& n) const{
if(n->left == NULL && n->right == NULL){
    return 1;
  }else if(n->left == NULL && n->right != NULL){
    return 1 + numNodesHelp(n->right);
  }else if(n->left != NULL && n->right == NULL){
    return 1 + numNodesHelp(n->left);
  }else{
    return 1 +numNodesHelp(n->left) + numNodesHelp(n->right);
  }
}
// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  /* if(height(n->right) - height(n->left) == 0 ||height(n->right) - height(n->left) == 1 ||height(n->right) - height(n->left) == -1 ){

  }*/
  //cout<<"I am balancing!"<<endl;
  if(height(n->right) - height(n->left) > 1){
    if(height(n->right->right) - height(n->right->left) < -1){
      rotateRight(n->right);
    }
    rotateLeft(n);
  }else if(height(n->right) - height(n->left) < -1){
    if(height(n->right->right) - height(n->right->left) > 1){
      rotateLeft(n->left);
    }
    rotateRight(n);
  }
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  //cout<< "I am left rotating" << endl;
  AVLNode* dummy = n->right;
  /* dummy->value = n->right->value;
  dummy->height = n->right->height;
  dummy->left = n->right->left;
  dummy->right = n->right->right;*/
  //cout << "reassignment 1 done" << endl;
  AVLNode* dummy2 = dummy->left;
  //cout << "reassignment 2 done" << endl;
  dummy->left = n;
  //cout << "reassignment 3 done" << endl;
  n->right = dummy2;
  //cout << "reassignment 4 done" << endl;
  n->right->left = dummy; // sig sev fault error
  n->height = max(height(n->left),height(n->right)) + 1;
  dummy->height = max(height(dummy->left),height(dummy->right)) + 1;
  return dummy;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  cout << "I am right rotating" << endl;
  AVLNode* dummy = n->left;
  AVLNode* dummy2 = dummy->right;
  dummy->right = n;
  n->left = dummy2;
  n->height = max(height(n->left),height(n->right)) + 1;
  dummy->height = max(height(dummy->left),height(dummy->right)) + 1;
  return dummy;
  
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
