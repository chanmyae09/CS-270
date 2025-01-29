#ifndef CS270_HASHTABLE
#define CS270_HASHTABLE

#include <string>
#include <list>
#include <utility>
#include <vector>
#include <exception>
#include <iostream>



int hashCode(const char* bytes, int len) {
  int result = 0;
  for (int i =0;i<len;i++){
    result = result*31+bytes[i];
  }
  return result;
}

int hashCode(int key) {
  return hashCode((char*)&key, sizeof(key));
}

int hashCode(const std::string& key) {
  //Convert string into an array of characters
  return hashCode(key.c_str(), key.length());
}

template<class K, class V>
class HashTable {
 public:
  typedef std::pair<K, V> Entry;
  typedef const std::pair<K, V> ConstEntry;
  typedef std::pair<K, V>* EntryPtr;
  typedef typename std::list<Entry>::iterator TableIter;

 private:
  std::vector< std::list<Entry> > theTable;
  int _size;

  void resize() {
    //Do we need to grow the array?
    if (theTable.size() > _size) {
      //Nope
      return;
    } else {
      _size = 0;
      std::vector< std::list<Entry> > oldTable = theTable;
      //Reset and resize theTable
      theTable.clear();
      theTable.resize(2*oldTable.size());

      //for each bucket
      for ( auto it = oldTable.begin(); it != oldTable.end(); it++) {
        for (TableIter it2 = (*it).begin(); it2 != (*it).end(); it2++) {
          Entry e = (*it2);
          insert(e.first, e.second );
        }
      }
    }
  }

  //Return a valid iterator if this list contains an entry matching the given key
  //Return an invalid iterator (bucket.end()) otherwise
  TableIter
  find_in_bucket(std::list<Entry>& bucket, const K& key) {
    //for each entry in bucket
    for ( TableIter it = bucket.begin() ; it != bucket.end(); it++) {
    //  if entry key matches given key return that entry
      if ( (*it).first == key) {
        return it;
      }
    }
    //Otherwise return invalid entry
    return bucket.end();
  }

 public:
  //Interfaces
  //void insert(ConstEntry e);
  HashTable() : theTable(3), _size(0) { };

  //Return the value that goes with this key, or throw an exception
  V& find(const K& key) {
    //Compute hadhcode for key
    int hc= hashCode(key);
    //Simple mod compression function
    int index = hc% theTable.size();
    //access the bucket at theTautoable[index], call helpter to find entry
    TableIter it = find_in_bucket(theTable[index],key);
    if(it !=theTable[index].end()){
      return (*it).second;
    }else{
      throw std::exception();
    }

  }

  void insert(const K& key, const V& value) {
    int hc = hashCode(key);
    int index = hc% theTable.size();
    TableIter it = find_in_bucket(theTable[index],key);
    if(it!=theTable[index].end()){
        (*it).second = value;
      }
      else{
        theTable[index].push_back(Entry(key,value));
        _size++;
      }
    }
  void remove(const K& key) { 
    int hc =hashCode(key);
    int index = hc% theTable.size();
    TableIter it = find_in_bucket(theTable[index],key);
    if(it!=theTable[index].end()){
      theTable[index].erase(it);
    }
    else 
      return;
  }

  int size() const {
    return _size;
  }
  bool isEmpty() const { return size() == 0; };

};

#endif //CS270_HASHTABLE
