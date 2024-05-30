#include <stdio.h>
#include <stdlib.h>
#include "../include/hashmap.h"
#include "../include/linkedlist.h"
#include "../include/BST.h"
#include "../include/sort.h"
#include "../include/arraylist.h"

int main() {
  // Test HashMap
  printf("======= Testing HashMap =======\n");

  // Create a hash map
  HashMap* map = hashmap_create(16);

  // Insert some key-value pairs
  hashmap_put(map, "apple", "fruit");
  hashmap_put(map, "banana", "fruit");
  hashmap_put(map, "carrot", "vegetable");

  // Retrieve and print the values
  printf("apple: %s\n", (char*)hashmap_get(map, "apple"));
  printf("banana: %s\n", (char*)hashmap_get(map, "banana"));
  printf("carrot: %s\n", (char*)hashmap_get(map, "carrot"));

  // Remove a key-value pair
  hashmap_remove(map, "banana");

  // Print the size of the hash map
  printf("Size of hash map: %u\n", hashmap_size(map));

  // Destroy the hash map
  hashmap_destroy(map, NULL); // No need to free individual entries

  // Test LinkedList
  printf("\n======= Testing LinkedList =======\n");

  LinkedList* list = linkedlist_create();

  // Add some elements
  linkedlist_add(list, "apple");
  linkedlist_add(list, "banana");
  linkedlist_add(list, "mango");

  // Retrieve and print elements
  printf("Element at index 0: %s\n", (char*)linkedlist_get(list, 0));
  printf("Element at index 1: %s\n", (char*)linkedlist_get(list, 1));
  printf("Element at index 2: %s\n", (char*)linkedlist_get(list, 2));

  // Remove an element from the list
  printf("Removing element at index 1...\n");
  linkedlist_remove(list, 1);

  // Print the list size
  printf("Size of the list: %u\n", linkedlist_size(list));

  // Retrieve and print elements again to confirm removal
  printf("Element at index 0: %s\n", (char*)linkedlist_get(list, 0));
  printf("Element at index 1: %s\n", (char*)linkedlist_get(list, 1));

  // Destroy the linked list and free memory
  linkedlist_destroy(list);

  // Test BST
  printf("\n======= Testing BST =======\n");

  BST* bst = bst_create();

  // Insert some values into the BST
  bst_insert(bst, 50);
  bst_insert(bst, 30);
  bst_insert(bst, 20);
  bst_insert(bst, 40);
  bst_insert(bst, 70);
  bst_insert(bst, 60);
  bst_insert(bst, 80);

  // Perform an inorder traversal of the BST
  printf("Inorder traversal of the BST: ");
  bst_inorder(bst->root);
  printf("\n");

  // Search for a value in the BST
  int search_value = 40;
  struct BST_Node* result = bst_search(bst, search_value); // Changed Node* to struct BST_Node*
  if (result != NULL) {
    printf("%d found in the BST\n", search_value);
  } else {
    printf("%d not found in the BST\n", search_value);
  }

  // Destroy the BST and free memory
  bst_destroy(bst);

  // Test Sorting Algorithm
  printf("\n======= Testing Sorting Algorithm =======\n");

  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Sort the array
  sort(arr, n);

  printf("Sorted array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");


  // Test ArrayList
  printf("\n======= Testing ArrayList =======\n");

  ArrayList* a_list = arraylist_create();

    // Add some elements to the array list
    printf("Adding elements to the array list:\n");
    for (int i = 0; i < 10; i++) {
        arraylist_add(a_list, i * 10);
    }

    // Print the elements of the array list
    printf("Elements of the array list: ");
    for (int i = 0; i < arraylist_size(a_list); i++) {
        printf("%d ", arraylist_get(a_list, i));
    }
    printf("\n");

    // Set an element at index 5
    printf("Setting an element at index 5...\n");
    arraylist_set(a_list, 5, 99);

    // Print the updated elements of the array list
    printf("Updated elements of the array list: ");
    for (int i = 0; i < arraylist_size(a_list); i++) {
        printf("%d ", arraylist_get(a_list, i));
    }
    printf("\n");

    // Remove an element at index 2
    printf("Removing an element at index 2...\n");
    arraylist_remove(a_list, 2);

    // Print the updated elements of the array list after removal
    printf("Updated elements of the array list after removal: ");
    for (int i = 0; i < arraylist_size(a_list); i++) {
        printf("%d ", arraylist_get(a_list, i));
    }
    printf("\n");

    // Print the size of the array list
    printf("Size of the array list: %d\n", arraylist_size(a_list));

    // Destroy the array list and free memory
    arraylist_destroy(a_list);
    printf("Array list destroyed.\n");

  return 0;
}

