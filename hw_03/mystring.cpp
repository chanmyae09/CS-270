#include "mystring.hpp"
#include <iostream>

bool CS270::string:: operator==(string& other)
{
    if(_size!= other._size){
        return false;
    }
    for (int i =0; i< _size;i++)
    {
        if(data[i]!=other.data[i])
        {
            return false;
        }
    }
    return true;
}

CS270::string CS270::string :: operator+(string& other)
{
    string result;
    for(int i=0; i<_size;i++){
        result.data[i] = data[i];
    }
    for (int i = 0; i<other._size; i++){
        result.data[_size+i]= other.data[i];
    }
    result._size= _size + other._size;
    return result;
}


CS270::string:: string(const char s[])
{   

    int len=0;
    while (s[len]!= '\0')
    {
        len++;
    }
    _size = len;
    for (int i = 0; i< len; i++){
        data[i]= s[i];
    }
}

int CS270::string:: length()
{
    return _size;
}

CS270::string CS270::string :: copy(string& other)
{
    string result;
    for (int i = 0; i< other._size; i++)
    {
        result.data[i]= other.data[i];
    }
    return result;
}
char somename = '\0';
char& CS270::string :: operator[](int index)
{
    if (index<0 || index>=_size){
        return somename;
    }
    else
        return data[index];    
}