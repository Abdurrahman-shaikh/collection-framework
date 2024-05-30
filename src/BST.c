#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

// Function to create a new Binary Search Tree
BST* bst_create() {
    BST* bst = (BST*)malloc(sizeof(BST));
    if (!bst) {
        return NULL; // Memory allocation failed
    }
    bst->root = NULL;
    return bst;
}

// Function to create a new node with the given value
struct BST_Node* create_node(int value) {
    struct BST_Node* newNode = (struct BST_Node*)malloc(sizeof(struct BST_Node));
    if (!newNode) {
        return NULL; // Memory allocation failed
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
void bst_insert_helper(struct BST_Node* root, int value) {
    if (value < root->data) {
        if (root->left == NULL) {
            root->left = create_node(value);
        } else {
            bst_insert_helper(root->left, value);
        }
    } else if (value > root->data) {
        if (root->right == NULL) {
            root->right = create_node(value);
        } else {
            bst_insert_helper(root->right, value);
        }
    }
}

void bst_insert(BST* bst, int value) {
    if (!bst || !bst->root) {
        bst->root = create_node(value);
    } else {
        bst_insert_helper(bst->root, value);
    }
}

// Function to search for a value in the BST
struct BST_Node* bst_search(BST* bst, int value) {
    struct BST_Node* current = bst->root;
    while (current != NULL && current->data != value) {
        if (value < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return current;
}

// Function to perform an inorder traversal of the BST
void bst_inorder(struct BST_Node* root) {
    if (root != NULL) {
        bst_inorder(root->left);
        printf("%d ", root->data);
        bst_inorder(root->right);
    }
}

// Function to destroy the BST and free memory
void bst_destroy_helper(struct BST_Node* root) {
    if (root != NULL) {
        bst_destroy_helper(root->left);
        bst_destroy_helper(root->right);
        free(root);
    }
}

void bst_destroy(BST* bst) {
    if (bst != NULL) {
        bst_destroy_helper(bst->root);
        free(bst);
    }
}

