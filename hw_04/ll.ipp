namespace CS270 {

//Constructor
template<class T>
forward_list<T>::forward_list() {
  head = NULL;
}

template<class T>
T& forward_list<T>::front() {
  return head->val;
}


//Check if list is empty
template<class T>
bool forward_list<T>::empty() {
  return head == NULL;
}
template<class T>
 forward_list<T>::~forward_list(){
  for (Node * temp= head; temp!=NULL;){
    Node* next = temp->next;
    delete temp;
    temp=next;
  }
 }

//Add an item
template<class T>
void forward_list<T>::push_front(const T& v) {
  Node* first = new Node(v);
  first->next = head;
  head = first;
}

template<class T>
void forward_list<T>::pop_front() {
  Node* toDelete = head;
  head = head->next;
  delete toDelete;
}

//Remove all copies of const T& val
template<class T>
void forward_list<T>::remove(const T& val) {
  Node* current = head;
  Node* prev = NULL; //No previous node at beginning
  while(current != NULL) {
    if (current->val == val) {
      if (prev != NULL) {
        prev->next = current->next;
      } else {
        head = current->next;
      }
      delete current;
      if (prev != NULL) {
        current = prev->next;
      } else {
        current = head;
      }
    } else {
      prev = current;
      current = current->next;
    }
  }
}

 //Remove consecutive duplicate values
template <class T>
void forward_list<T>:: unique(){
  if (head == NULL)
    return;
  Node* base = head;
  Node* candidate = head->next;
  while(candidate!=NULL){
  //Should we remove this?
    if (candidate->val==base->val){
      base->next = candidate->next;
      delete candidate; 
  }
  else{
    base= base->next;
  }
  candidate = base->next;
  }
}

template<class T>
void forward_list<T>:: merge(forward_list<T>& other ){
  Node* temp = head;
  Node* trail = NULL;
  if(temp == NULL && other.head==NULL){
    return;
  }
  if(temp == NULL && other.head!= NULL){
    head = other.head;
  }
  if (temp!= NULL && other.head == NULL){
    return;
  }


  if(other.head->val < head->val){
    Node* toMove = other.head;
    other.head = other.head->next;
    toMove->next = head;
    head = toMove;
    trail = toMove;
  }


  while(other.head!=NULL && temp != NULL){
    if(temp->val < other.head->val){
      trail = temp;
      temp = temp->next;
    }
    else{
      Node* toMove = other.head;
      other.head = other.head->next;
      trail->next = toMove;
      toMove->next = temp;
      trail = toMove;

    }
  }

  if (other.head!=NULL){
    temp->next = other.head;
  }
}




}