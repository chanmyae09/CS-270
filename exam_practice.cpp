// template <class T>
// class TwoDArray{

// };
#include <string>
#include <utility>
#include <vector>
#include <exception>
#include <iostream>


template<class K, class T>
class ArrOfPair{
    public:
        typedef std::pair<K, T> Entry;
        typedef std::pair<K, T>* EntryPtr;
        class Iterator{
            public:
                Iterator(EntryPtr ptr): _ptr(ptr){}
                Entry& operator*(){
                    return *_ptr;
                }
                Entry& operator->(){
                    return *_ptr;
                }
                void operator++(){
                    ++_ptr;
                }
                bool operator==(const Iterator& other) const{
                    return _ptr == other._ptr;  
                }
                bool operator!=(const Iterator& other)const{
                    return _ptr != other._ptr;  
                }
            private:
                EntryPtr _ptr;

        };
        Iterator begin() {
            return Iterator(_array);  // Return an iterator pointing to the first element
        }

        Iterator end() {
            return Iterator(_array + _size);  // Return an iterator pointing to one past the last element
        }
        ArrOfPair(int size){
            _numoccupied = 0;
            _size = size;
           _array = new Entry[size];
        }
        ~ArrOfPair(){
            delete [] _array;
        }
        Entry& operator[](int index){
            return _array[index];
        }
        int size(){
            return _size;
        }
        void resize(){
            if(_numoccupied<_size ){
                //resize
                return;
            }
            else{
                EntryPtr newArray = new Entry[_size+100];
                for(int i=0; i <_numoccupied;i++){
                    newArray[i] = _array[i]
                }
                delete[] _array;
                _array = newArray;
                _size += 100;
            }
        }
        void clear(){
            delete[]_array;
            _numoccupied = 0;
        }
        T& find(const K& key) {
            for(Iterator it = begin(); it++;it!=end()){
                if((*it).first==key){
                    return (*it).second// chatgpt says that it->second also works..
                }
            }
        }
        void add(const K& key, const T& value){
            if(_numoccupied >=_size){
                resize();
            }
            _array[_numoccupied] = Entry(key, value);
        }
        

    private:
        EntryPtr _array;
        int _size;
        int _numoccupied;
};

