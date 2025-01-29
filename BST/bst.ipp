#include <algorithm>
#include <cstddef>
#include <vector>

template<class E>
BST<E>::BST(const E& val) {
  root = new Node(val);
  _size = 1;
}

template<class E>
BST<E>::BST() : root(NULL), _size(0) { }

template<class E>
void BST<E>:: add(const E& val){
  Node* current = root;
  Node* toInsert = new Node(val);
  while(current!=NULL){
    if (current->val < val){
      if(current->right ==NULL){
        current->right = toInsert;
        toInsert->parent = current;
        break;
      }
      current = current->right;
    }
    else{
      if(current->left ==NULL){
        current->left = toInsert;
        toInsert->parent = current;
        break;
      }
      current = current->left;
    }
  }
}
template<class E>
bool BST<E>:: contains(const E& val){
  Node* current = root;
  while(current!= NULL){
    if(current->val < val){
      current= current->right;
    }
    else if(current-> val == val){
      return true;
    }
    else{
      current= current->left;
    }
  }
  return false;
}
template<class E>
void BST<E>:: remove(const E& val){
  if(contains(val)== false){
    return;
  }
  else{
      Node* current = root;
      while(current!= NULL){
      if(current->val < val){
        current= current->right;
      }
      else if(current-> val == val){
        delete current;
      }
      else{
        current= current->left;
      }
    }
  }
}
