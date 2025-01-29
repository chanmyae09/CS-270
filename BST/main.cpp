#include "bst.h"
#include <cassert>
#include <iostream>
using namespace std;

int main() {
  BST<int> tree(5);
  cout << tree.contains(2)<<endl;
  tree.add(2);
  tree.add(4);
  tree.add(10);
  cout << tree.contains(2)<<endl;
  tree.remove(2);
  cout<<tree.contains(2)<<endl;
}
