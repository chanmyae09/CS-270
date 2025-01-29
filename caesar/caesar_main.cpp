//In this file, use the Ceasar class from the library you just created to 
// interact with the user.  You may reuse code you wrote for the 
// previous assignment here if you think it would be useful, but the 
// current application MUST use the new object-oriented library interface 
// to do encoding and decoding.
#include "Caesar.h"
#include <iostream>
#include<string>
using namespace std;

int main(){
    string enc, dec;
    Caesar c("key");
    enc = c.encode("message");
    cout << enc<< endl;
    dec = c.decode(enc);
    cout<< dec;
    cout<< "This is a test for git";
    return 0;

};

