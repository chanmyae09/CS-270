#include "hashtable.h"
#include <gtest/gtest.h>

//Test file for our hash table


using namespace std;

TEST(HT, hashtest) {
  int keys[] = {4, 9, 18, 22, 50, 42};
  std::string values[] = {
    "dog",
    "boat",
    "polar bear",
    "frog",
    "rock",
    "meaning of life"
  };
  HashTable<int, string> table;
  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(i, table.size());
    table.insert(keys[i], values[i]);
  }
  EXPECT_EQ(5, table.size());
  //If you get this far, insert doesn't crash, but we're still not sure if the 
  //  values are actually there.

  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(values[i], table.find(keys[i]));
  }

  //If you get this far, great, you found everything you inserted!
  //Now, we remove every item, one at a time, and verify that the 
  //  item no longer exists, but the others still do, and size is 
  //  adjusted appropriately.

  for (int i = 5; i >=0; i--) {
    table.remove(keys[i]);
    EXPECT_THROW(table.find(keys[i]), std::exception);
    for (int j = 0; j < i; j++) {
      EXPECT_EQ(values[j], table.find(keys[j]));
    }
    EXPECT_EQ(i, table.size());
  }

  //Can you think of other test cases that we haven't fully checked for yet?
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
