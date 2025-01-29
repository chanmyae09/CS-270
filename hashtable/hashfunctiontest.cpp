#include <iostream>
#include <string>

int hashCode(const char* bytes, int len) {
    int result = 0;
    for (int i = 0; i < len; i++) {
        result = result * 31 + bytes[i];
    }
    return result;
}

int hashCode(int key) {
    return hashCode((char*)&key, sizeof(key));
}

int hashCode(const std::string& key) {
    return hashCode(key.c_str(), key.length());
}

int main() {
    // Test with a string
    std::string str = "hello";
    int strHash = hashCode(str);
    std::cout << "Hash of string 'hello': " << strHash << std::endl;

    // Test with an integer
    int num = 1234;
    int numHash = hashCode(num);
    std::cout << "Hash of integer 1234: " << numHash << std::endl;

    // Test with a different string
    std::string anotherStr = "world";
    int anotherStrHash = hashCode(anotherStr);
    std::cout << "Hash of string 'world': " << anotherStrHash << std::endl;

    return 0;
}