#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct TreeNode {
    char* key;
    char* value;
    struct TreeNode* parent;  // Pointer to the parent node
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;


typedef struct TreeMap {
    TreeNode* root;
    size_t size;  // Number of elements in the TreeMap

    // Function pointers for operations on the TreeMap
    void (*dump)(struct TreeMap* map);

    bool (*insert)(struct TreeMap* map, const char* key, const char* value);
    const char* (*get)(const struct TreeMap* map, const char* key);
    bool (*remove)(struct TreeMap* map, const char* key);
    bool (*contains)(const struct TreeMap* map, const char* key);
    void (*destroy)(struct TreeMap* map);
    // Additional fields can be added as needed
} TreeMap;

/**
 * Creates a new TreeMap.
 * @return A pointer to the newly created TreeMap.
 */
TreeMap* create_tree_map();

/**
 * Destroys the TreeMap and frees its resources.
 * @param map The TreeMap to destroy.
 */
void destroy_tree_map(TreeMap* map);

/**
 * Inserts a key-value pair into the TreeMap.
 * @param map The TreeMap to insert into.
 * @param key The key to insert.
 * @param value The value associated with the key.
 * @return True if the insertion was successful, false otherwise.
 */


void tree_map_dump(TreeMap* map);

bool tree_map_insert(TreeMap* map, const char* key, const char* value);

/**
 * Retrieves a value by its key from the TreeMap.
 * @param map The TreeMap to search in.
 * @param key The key to look for.
 * @return The value associated with the key, or NULL if the key does not exist.
 */
const char* tree_map_get(const TreeMap* map, const char* key);

/**
 * Removes a key-value pair from the TreeMap.
 * @param map The TreeMap to remove from.
 * @param key The key to remove.
 * @return True if the removal was successful, false if the key was not found.
 */
bool tree_map_remove(TreeMap* map, const char* key);

/**
 * Checks if a key exists in the TreeMap.
 * @param map The TreeMap to check.
 * @param key The key to look for.
 * @return True if the key exists, false otherwise.
 */
bool tree_map_contains(const TreeMap* map, const char* key);

size_t tree_map_size(const TreeMap* map);

#ifdef __cplusplus
}
#endif
