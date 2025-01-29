#include <forward_list>
#include <gtest/gtest.h>
#include "ll.h"

//Test file for our linked list


//To test our linked list class, use this line to search for classes in the CS270 namespace
using namespace CS270;
//To test your test cases, use this line to search for classes in the std namespace
//using namespace std;

TEST(SLL, constructor) {
  //Empty constructors only - passes if it doesn't crash
  forward_list<int> intlist;
  forward_list<float> floatlist;
}

TEST(SLL, front_and_push) {
  forward_list<int> list;
  list.push_front(0);
  EXPECT_EQ(0, list.front());
  list.push_front(1);
  EXPECT_EQ(1, list.front());
}

TEST(SLL, pop) {
  forward_list<int> list;
  list.push_front(0);
  list.push_front(1);
  list.push_front(2);
  EXPECT_EQ(2, list.front());
  list.pop_front();
  EXPECT_EQ(1, list.front());
  list.pop_front();
  EXPECT_EQ(0, list.front());
}

TEST(SLL, empty) {
  forward_list<int> list;
  //Empty
  EXPECT_EQ(true, list.empty());
  //Size 1
  list.push_front(0);
  EXPECT_EQ(false, list.empty());
  //Size 2
  list.push_front(1);
  EXPECT_EQ(false, list.empty());
  //Size 3
  list.push_front(2);
  EXPECT_EQ(false, list.empty());
  //Size 2
  list.pop_front();
  EXPECT_EQ(false, list.empty());
  //Size 1
  list.pop_front();
  EXPECT_EQ(false, list.empty());
  //Empty again
  list.pop_front();
  EXPECT_EQ(true, list.empty());
}

TEST(SLL, remove) {
  forward_list<int> list;
  list.push_front(0);
  list.push_front(1);
  list.push_front(2);
  list.remove(1);
  EXPECT_EQ(2, list.front());
  list.pop_front();
  ASSERT_EQ(false, list.empty());
  EXPECT_EQ(0, list.front());
  list.pop_front();
  EXPECT_EQ(true, list.empty());
}
TEST(SLL,unique){
  forward_list<int> list;
  list.push_front(0);
  list.push_front(1);
  list.push_front(1);
  list.push_front(1);
  list.unique();
  ASSERT_EQ(false, list.empty());
  EXPECT_EQ(1, list.front());
  list.pop_front();
  ASSERT_FALSE(list.empty());
  EXPECT_EQ(0, list.front());
  list.pop_front();
  EXPECT_TRUE(list.empty());
  forward_list<float>flist;
  flist.unique();
}

// forward_list<int>&& buildList(int aname[],int size){
//   forward_list<int> list;
//   for (int i = 0; i< size; i++){
//     list.push_front(aname[i]);
//   }
//   return list;
// }


TEST (SLL, merge){
  // int array1[] = {1, 2, 3, 4, 5};
  // forward_list<int> list1(buildList(array1, 5);
  forward_list<int> list1;
  list1.push_front(6);
  list1.push_front(4);
  list1.push_front(2);
  forward_list<int> list2;
  list2.push_front(7);
  list2.push_front(1);
  list2.push_front(0);
  
  list1.merge(list2);
  EXPECT_EQ(0, list1.front());
  list1.pop_front();
  EXPECT_EQ(1, list1.front());



}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
