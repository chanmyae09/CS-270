#ifndef CS270_STRING
#define CS270_STRING
#include <cstring>

namespace CS270 {

const int CAPACITY = 1000;

class string {
  //Public methods of a string, including operators, construtors, 
  // destructor, and other methods
 public:
  // compare current object to another for equality
  // s1 == s2
  bool operator==(string& other);
  // concatenation
  // string news = s1 + s2;
  string operator+(string& other);
  // cout << s[i];
  // s[i] = 'x'
  char& operator[](int index);
  // string mystring = "some string";
  // string mystring("some string");
  
  string(const char s[]);
  // length
  int length();
  string copy(string& other);
  // copies the string

 private:
  //Empty constructor is a useful way to declare local string objects 
  // you plan to initialize immediately in other class functions (like operator+), 
  // but making it private prevents other code from creating an uninitialized string.
  string() {};
  //Declare necessary fields here
  int _size;
  char data[CAPACITY];
};
}

#endif //define CS270_STRING
