#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

// Function to create a new dynamic array list
ArrayList* arraylist_create() {
    ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
    if (!list) {
        return NULL; // Memory allocation failed
    }
    list->array = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    if (!list->array) {
        free(list);
        return NULL; // Memory allocation failed
    }
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
    return list;
}

// Function to resize the array list
void resize(ArrayList* list) {
    list->capacity *= 2;
    list->array = (int*)realloc(list->array, list->capacity * sizeof(int));
    if (!list->array) {
        printf("Memory reallocation failed\n");
        exit(1);
    }
}

// Function to add an element to the array list
void arraylist_add(ArrayList* list, int element) {
    if (list->size == list->capacity) {
        resize(list);
    }
    list->array[list->size++] = element;
}

// Function to get the element at the specified index
int arraylist_get(ArrayList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Index out of bounds\n");
        exit(1);
    }
    return list->array[index];
}

// Function to set the element at the specified index
void arraylist_set(ArrayList* list, int index, int element) {
    if (index < 0 || index >= list->size) {
        printf("Index out of bounds\n");
        exit(1);
    }
    list->array[index] = element;
}

// Function to remove the element at the specified index
void arraylist_remove(ArrayList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Index out of bounds\n");
        exit(1);
    }
    for (int i = index; i < list->size - 1; i++) {
        list->array[i] = list->array[i + 1];
    }
    list->size--;
}

// Function to get the size of the array list
int arraylist_size(ArrayList* list) {
    return list->size;
}

// Function to destroy the array list and free memory
void arraylist_destroy(ArrayList* list) {
    free(list->array);
    free(list);
}

