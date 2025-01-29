#ifndef BST_H
#define BST_H
#include <algorithm>
#include <cstddef>
#include <vector>

template<class E>
class BST {
 private:
  class Node {
   public:
    Node(const E& item) : val(item), left(NULL), right(NULL), parent(NULL),
      height(-1), depth(-1), index(-1)
    { }
    E val;
    Node* left;
    Node* right;
    Node* parent;
    int height, depth, index;
  };

 public:
  BST(const E& val);
  BST();
  void add(const E& val);
  bool contains(const E& val);
  void remove(const E& val);
  int size() const;

 private:
  Node* root;
  int _size;

};

#include "bst.ipp"
#endif //BST_H
