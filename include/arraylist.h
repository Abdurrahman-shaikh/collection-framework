#ifndef ARRAYLIST_H
#define ARRAYLIST_H

// Define initial capacity of the array list
#define INITIAL_CAPACITY 10

// Structure representing the dynamic array list
typedef struct ArrayList {
    int* array;
    int size;
    int capacity;
} ArrayList;

// Function to create a new dynamic array list
ArrayList* arraylist_create();

// Function to add an element to the array list
void arraylist_add(ArrayList* list, int element);

// Function to get the element at the specified index
int arraylist_get(ArrayList* list, int index);

// Function to set the element at the specified index
void arraylist_set(ArrayList* list, int index, int element);

// Function to remove the element at the specified index
void arraylist_remove(ArrayList* list, int index);

// Function to get the size of the array list
int arraylist_size(ArrayList* list);

// Function to destroy the array list and free memory
void arraylist_destroy(ArrayList* list);

#endif /* ARRAYLIST_H */

