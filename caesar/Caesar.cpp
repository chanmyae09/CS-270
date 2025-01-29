#include "Caesar.h"
#include <iostream>
#include <string>
using namespace std;

static const int maxchar = 'z';
static const int minchar = ' ';
static const int charrange = 1 + maxchar - minchar;

// Caesar constructor, accepts a single string argument as the cipher
// key


    // Caesar constructor, accepts a single string argument as the cipher
    // key
    Caesar::Caesar(string cipherKey) {
        key = cipherKey;
    }

    string Caesar::get_key() const {
        return key;
    }
    // decode the string argument using the key, return decoded string

  
    string Caesar::decode(string message) const {
        string decoded("");
        int i, shifted_reverse, intchar_reverse, result_reverse, required;
        for (i = 0; i < message.length(); i++) {
            result_reverse = message[i] - minchar;
            shifted_reverse = (result_reverse - (key[i % key.length()] - minchar) + charrange) % charrange;
            required = shifted_reverse + minchar;
            decoded += required;
    }
    return decoded;
}




    // encode the string argument using the key, return encoded string

    string Caesar::encode (string message) const{
        int i, intchar, shiftedchar;
        string result("");
        for (i = 0; i < message.length();i++ ){
            intchar = message[i] - minchar;
            shiftedchar = (intchar + key[i% key.length()]- minchar)% charrange;
            result += (shiftedchar + minchar);
    };
        return result;
    }

 



