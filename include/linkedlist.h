#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Linked list node structure
typedef struct Node {
    void* data;
    struct Node* next;
} Node;

// Linked list structure
typedef struct LinkedList {
    Node* head;
    unsigned int size;
} LinkedList;

// Function to create a new linked list
LinkedList* linkedlist_create();

// Function to add an element to the linked list
void linkedlist_add(LinkedList* list, void* data);

// Function to get an element from the linked list by index
void* linkedlist_get(LinkedList* list, unsigned int index);

// Function to remove an element from the linked list by index
void linkedlist_remove(LinkedList* list, unsigned int index);

// Function to get the size of the linked list
unsigned int linkedlist_size(LinkedList* list);

// Function to destroy the linked list and free memory
void linkedlist_destroy(LinkedList* list);

#endif /* LINKEDLIST_H */

