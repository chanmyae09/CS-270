#include <cstddef>

namespace CS270 {
template<class T>
class forward_list {
  
 private:
  class Node {
   public:
    T val;
    Node* next;
    Node(const T& v) : val(v), next(NULL) {}
  };

  //Pointer to the beginning of the linked list
  Node* head;

  //Prevent copy and assignment by declaring private functions (implementations not needed)
  forward_list(forward_list& other);
  forward_list& operator=(forward_list& other);

 public:
  forward_list();
  ~forward_list();

  //Insert an item at the beginning of the list
  void push_front(const T& v);

  //Returns the value at the head of the list
  T& front();

  //Remove the first item from the list
  void pop_front();

  //Is the list empty?
  bool empty();

  //Remove items matching val from the list
  void remove(const T& val);

  void merge(forward_list& other);

  //Remove consecutive duplicate values
  void unique();

};

}

#include "ll.ipp"
