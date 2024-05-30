#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// Function to create a new linked list
LinkedList* linkedlist_create() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (!list) {
        return NULL; // Memory allocation failed
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

// Function to add an element to the linked list
void linkedlist_add(LinkedList* list, void* data) {
    if (!list) {
        return; // Invalid argument
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        return; // Memory allocation failed
    }

    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

// Function to get an element from the linked list by index
void* linkedlist_get(LinkedList* list, unsigned int index) {
    if (!list || index >= list->size) {
        return NULL; // Invalid arguments
    }

    Node* current = list->head;
    for (unsigned int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->data;
}

// Function to remove an element from the linked list by index
void linkedlist_remove(LinkedList* list, unsigned int index) {
    if (!list || index >= list->size) {
        return; // Invalid arguments
    }

    Node* current = list->head;
    Node* previous = NULL;

    for (unsigned int i = 0; i < index; i++) {
        previous = current;
        current = current->next;
    }

    if (previous) {
        previous->next = current->next;
    } else {
        list->head = current->next;
    }

    free(current);
    list->size--;
}

// Function to get the size of the linked list
unsigned int linkedlist_size(LinkedList* list) {
    if (!list) {
        return 0; // Invalid argument
    }
    return list->size;
}

// Function to destroy the linked list and free memory
void linkedlist_destroy(LinkedList* list) {
    if (!list) {
        return; // Invalid argument
    }

    Node* current = list->head;
    while (current) {
        Node* next = current->next;
        free(current);
        current = next;
    }

    free(list);
}

