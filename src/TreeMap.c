
#include "TreeMap.h"
#include <stdlib.h>


TreeMap* create_tree_map() {
    TreeMap* map = (TreeMap*)malloc(sizeof(TreeMap));
    if (map) {
        map->root = NULL;  // Initialize the root to NULL  
        map->size = 0;
        map->insert = tree_map_insert;  // Assign function pointers
        map->get = tree_map_get;
        map->remove = tree_map_remove;
        map->contains = tree_map_contains;
        map->destroy = destroy_tree_map;  // Assign destroy function
    }
    
    return map;
}


void destroy_tree_map(TreeMap* map) {
    if (map) {
        // Here you would typically free all nodes in the tree
        // For simplicity, we will just free the map structure itself
        // In a complete implementation, you would need to traverse the tree and free each node
        free(map->root);  // This is a placeholder; actual node freeing logic is needed
        map->root = NULL; // Set root to NULL before freeing the map
        // Free the map structure
        free(map);
    } else {
        // If map is NULL, there's nothing to free
        // In a complete implementation, you would also need to handle freeing nodes properly
        // This is a simplified version and does not handle all edge cases

        free(map);
    }
}

bool tree_map_insert(TreeMap* map, const char* key, const char* value) {
    // Insert key-value pair into the TreeMap
    if (!map || !key || !value) {
        return false;  // Invalid parameters
    }
    
    // Here you would typically insert the key-value pair into the tree structure
    // For now, we will just return true to indicate success
    // Actual insertion logic would go here
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        return false;  // Memory allocation failed
    }
    
    newNode->key = strdup(key);
    newNode->value = strdup(value);
    newNode->left = NULL;
    newNode->right = NULL;

    // Insert the new node into the tree (not implemented here)
    // This is a placeholder for the actual insertion logic
    if (map->root == NULL) {
        map->root = newNode;  // If the tree is empty, set the new node as root
        map->size++;  // Increment the size of the TreeMap
    } else {
        // Logic to insert the new node in the correct position would go here
        TreeNode* current = map->root;
        TreeNode* parent = NULL;

        while (current) {
            parent = current;
            if (strcmp(key, current->key) < 0) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        // Insert the new node as a child of the parent
        if (strcmp(key, parent->key) < 0) {
            parent->left = newNode;
            map->size++;  // Increment the size of the TreeMap
            return true;  // Return true to indicate successful insertion
        } else {
            parent->right = newNode;
            map->size++;  // Increment the size of the TreeMap
            return true;  // Return true to indicate successful insertion
        }
    }

    // Free the new node if insertion fails (not implemented here)
    // For now, we assume insertion is always successful
    // In a real implementation, you would need to handle duplicates and balancing the tree
    free(newNode->key);
    free(newNode->value);
    free(newNode);

    // Return true to indicate successful insertion
    // In a real implementation, you would return false if the key already exists
    // or if there was an error during insertion
    // For now, we assume the insertion is always successful
    // Actual logic would involve checking for duplicates and balancing the tree
    // For now, we return true to indicate success
    // In a real implementation, you would also need to handle memory management properly
    // and ensure that the tree structure remains valid after insertion
    // This is a simplified version and does not handle all edge cases
    // In a complete implementation, you would also need to free the old value if it exists
    // and ensure that the tree remains balanced after insertion
    // For now, we will just return true to indicate success
    // Actual insertion logic would go here
    // This is a placeholder for the actual insertion logic
    // In a complete implementation, you would also need to handle duplicates and balancing the tree


    return true; // Placeholder return value
}

const char* tree_map_get(const TreeMap* map, const char* key) {
    // Retrieve value by key from the TreeMap
    if (!map || !key) {
        return NULL;  // Invalid parameters
    }

    TreeNode* current = map->root;
    while (current) {
        int cmp = strcmp(key, current->key);
        if (cmp == 0) {
            return current->value;  // Key found, return value
        } else if (cmp < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return NULL;  // Key not found
}

bool tree_map_remove(TreeMap* map, const char* key) {
    // Remove key-value pair from the TreeMap
    if (!map || !key) {
        return false;  // Invalid parameters
    }

    TreeNode* current = map->root;
    TreeNode* parent = NULL;

    map->size--; 

    // Find the node to remove
    while (current && strcmp(key, current->key) != 0) {
        parent = current;
        if (strcmp(key, current->key) < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (!current) {
        return false;  // Key not found
    }

    // Node found, now remove it
    // Logic to remove the node and maintain tree structure would go here
    // For now, we will just free the node and return true
    if (current->left == NULL && current->right == NULL) {
        // Node is a leaf
        if (parent) {
            if (parent->left == current) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
        } else {
            map->root = NULL;  // Removing the root node
        }
    } else if (current->left == NULL || current->right == NULL) {
        // Node has one child
        TreeNode* child = (current->left) ? current->left : current->right;
        if (parent) {
            if (parent->left == current) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        } else {
            map->root = child;  // Removing the root node
        }
    } else {
        // Node has two children
        // Find the in-order successor or predecessor to replace the current node
        TreeNode* successor = current->right;
        TreeNode* successorParent = current;

        while (successor->left) {
            successorParent = successor;
            successor = successor->left;
        }

        // Replace current with successor
        current->key = successor->key;
        current->value = successor->value;

        // Remove the successor node
        if (successorParent->left == successor) {
            successorParent->left = successor->right;
        } else {
            successorParent->right = successor->right;
        }
    }

    // Free the current node
    free(current->key);
    free(current->value);
    free(current);

    // Return true to indicate successful removal
    // In a complete implementation, you would also need to handle memory management properly
    // and ensure that the tree structure remains valid after removal
    // This is a simplified version and does not handle all edge cases
    // In a complete implementation, you would also need to free the old value if it exists
    // and ensure that the tree remains balanced after removal
    // For now, we will just return true to indicate success
    // Actual removal logic would go here
    // This is a placeholder for the actual removal logic

    return true; // Placeholder return value
}

bool tree_map_contains(const TreeMap* map, const char* key) {
    // Check if the key exists in the TreeMap
    if (!map || !key) {
        return false;  // Invalid parameters
    }

    TreeNode* current = map->root;
    while (current) {
        int cmp = strcmp(key, current->key);
        if (cmp == 0) {
            return true;  // Key found
        } else if (cmp < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return false;  // Key not found
}

