#ifndef BST_H
#define BST_H

// Structure representing a node in the binary search tree
typedef struct BST_Node {
    int data;
    struct BST_Node* left;
    struct BST_Node* right;
} BST_Node;

// Binary Search Tree structure
typedef struct BST {
    struct BST_Node* root;
} BST;

// Function declarations
BST* bst_create();
void bst_insert(BST* bst, int value);
struct BST_Node* bst_search(BST* bst, int value);
void bst_inorder(struct BST_Node* root);
void bst_destroy(BST* bst);

#endif /* BST_H */

