#pragma once

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct TreeMap TreeMap;

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

#ifdef __cplusplus
}
#endif
