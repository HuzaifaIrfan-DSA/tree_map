
#include "TreeMap.h"  // Include the header file for TreeMap
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(TreeMapTest, Hi) {
  struct TreeMap *treeMap;

  // Initialize the TreeMap.
  treeMap = create_tree_map();
  ASSERT_NE(treeMap, nullptr);  // Ensure the TreeMap was created successfully.

  // Check if the TreeMap is initially empty.
  EXPECT_EQ(treeMap->size(treeMap), 0);

  // Insert some key-value pairs into the TreeMap.
  EXPECT_TRUE(treeMap->insert(treeMap,"one", "1"));
  EXPECT_TRUE(treeMap->insert(treeMap,"two", "2"));
  EXPECT_TRUE(treeMap->insert(treeMap,"three", "3"));

  // Check if the size of the TreeMap is as expected.
  EXPECT_EQ(treeMap->size(treeMap), 3);

  // Check if the values can be retrieved correctly.
  EXPECT_EQ(treeMap->get(treeMap,"one"), "1");
  EXPECT_EQ(treeMap->get(treeMap,"two"), "2");
  EXPECT_EQ(treeMap->get(treeMap,"three"), "3");

  // Check if a non-existing key returns an empty string.
  EXPECT_EQ(treeMap->get(treeMap,"four"), "");

  // Remove a key-value pair and check if it was successful.
  EXPECT_TRUE(treeMap->remove(treeMap,"two"));
  EXPECT_EQ(treeMap->size(treeMap), 2);
  EXPECT_EQ(treeMap->get(treeMap,"two"), "");  // Should return an empty string after removal.

  // Check if the removed key no longer exists.
  EXPECT_FALSE(treeMap->contains(treeMap,"two"));

  // Clean up the TreeMap resources.
  destroy_tree_map(treeMap); 
}
