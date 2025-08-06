
#include "TreeMap.h"  // Include the header file for TreeMap
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(TreeMapTest, Hi) {
  struct TreeMap *treeMap;

  // Initialize the TreeMap.
  treeMap = create_tree_map();
  ASSERT_NE(treeMap, nullptr);  // Ensure the TreeMap was created successfully.

  // Check if the TreeMap is initially empty.
  EXPECT_EQ(treeMap->size, 0);

  // Insert some key-value pairs into the TreeMap.
  EXPECT_TRUE(treeMap->insert(treeMap,"one", "1"));
  EXPECT_TRUE(treeMap->insert(treeMap,"two", "2"));
  EXPECT_TRUE(treeMap->insert(treeMap,"three", "3"));

  // Check if the size of the TreeMap is as expected.
  EXPECT_EQ(treeMap->size, 3);

  // Check if the values can be retrieved correctly.
  EXPECT_EQ(strcmp(treeMap->get(treeMap,"one"), "1"), 0);
  EXPECT_EQ(strcmp(treeMap->get(treeMap,"two"), "2"), 0);
  EXPECT_EQ(strcmp(treeMap->get(treeMap,"three"), "3"), 0);

  // Check if a non-existing key returns NULL.
  EXPECT_EQ(*treeMap->get(treeMap,"four"), NULL);

  // Remove a key-value pair and check if it was successful.
  EXPECT_TRUE(treeMap->remove(treeMap,"two"));
  EXPECT_EQ(treeMap->size, 2);
  EXPECT_EQ(*treeMap->get(treeMap,"two"), NULL);  // Should return an empty string after removal.

  // Check if the removed key no longer exists.
  EXPECT_FALSE(treeMap->contains(treeMap,"two"));

  // Clean up the TreeMap resources.
  destroy_tree_map(treeMap); 
}
