
#include "TreeMap.h"
#include <stdlib.h>


TreeMap* create_tree_map() {
    TreeMap* map = (TreeMap*)malloc(sizeof(TreeMap));
    if (map) {
        map->root = NULL;  // Initialize the root to NULL  
        map->size = 0;
        // Initialize function pointers
        map->dump = tree_map_dump;  // Assign function pointers
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

void tree_map_inorder_print(TreeNode* node, int level) {
    for (int i = 0; i < level; i++) {
        printf("| ");  // Indent for better readability
    }
    if (node == NULL){ 
         printf("\n");
        return;
    }
    printf("Key: %s, Value: %s, Parent: %s\n", node->key, node->value ,node->parent ? node->parent->key : "NULL");
    tree_map_inorder_print(node->left, level + 1);
    tree_map_inorder_print(node->right, level + 1);
}


void tree_map_dump(TreeMap* map) {
    // Dump the contents of the TreeMap
    if (!map) {
        return;  // If map is NULL, do nothing
    }

    // In a complete implementation, you would traverse the tree and print each key-value pair
    // This is a simplified version and does not perform any actual dumping
    printf("TreeMap contents (size: %zu):\n", map->size);
    // You would typically use an in-order traversal to print the tree contents
    // For now, we will just print a placeholder message
    if (map->root == NULL) {
        printf("TreeMap is empty.\n");
        return;
    }
    tree_map_inorder_print(map->root, 0);

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
    newNode->parent = NULL;  // Initialize parent to NULL
    newNode->left = NULL;
    newNode->right = NULL;

    // Insert the new node into the tree (not implemented here)
    // This is a placeholder for the actual insertion logic
    if (map->root == NULL) {
        map->root = newNode;  // If the tree is empty, set the new node as root
        map->size++;  // Increment the size of the TreeMap
        return true;  // Return true to indicate successful insertion
    }
    
    // Logic to insert the new node in the correct position would go here
    TreeNode* current = map->root;
    TreeNode* parent = map->root->parent;

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
    
    } else {
        parent->right = newNode;
    }
    newNode->parent = parent;  // Set the parent of the new node
    map->size++;
    return true;  // Return true to indicate successful insertion


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
            // printf("Key found: %s, Value: %s\n", current->key, current->value);
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
    map->size--; 

    // Find the node to remove
    while (current && strcmp(key, current->key) != 0) {
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
        if (current->parent) {
            if (current->parent->left == current) {
                current->parent->left = NULL;
            } else {
                current->parent->right = NULL;
            }
        } else {
            map->root = NULL;  // Removing the root node
        }


    } else if (current->left == NULL || current->right == NULL) {
        // Node has one child
        TreeNode* child = (current->left) ? current->left : current->right;
        if (current->parent) {
            if (current->parent->left == current) {
                current->parent->left = child;

            } else {
                current->parent->right = child;
            }
            child->parent = current->parent;  // Set the parent of the child
        } else {
            child->parent = NULL;  // If it's the root node, set child as new root
            map->root = child;  // Removing the root node
        }
    } else {

        
    }



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

