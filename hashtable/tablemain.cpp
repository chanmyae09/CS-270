#include "hashtable.h"
#include <string>
#include <iostream>
#include <list>

int main() {
  HashTable<int, std::string> table;

  int keys[] = {4, 9, 18, 22, 50, 42};
  std::string values[] = {
    "dog",
    "boat",
    "polar bear",
    "frog",
    "rock",
    "meaning of life"
  };

  for (int i = 0; i < 5; i++) {
    table.insert(keys[i], values[i]);
  }

  for (int i = 0; i < 5; i++) {
    if (values[0] != table.find(keys[0])) {
      std::cout << "problem!" << std::endl;
    }
  }
}
