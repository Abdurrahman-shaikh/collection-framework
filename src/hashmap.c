// hashmap.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

// Define the initial capacity of the hash map
#define INITIAL_CAPACITY 16

// Hash function
static unsigned int hash(const void* key, unsigned int capacity) {
    // Simple hash function for demonstration purposes
    unsigned long hash_value = 0;
    const char* str = (const char*)key;
    while (*str) {
        hash_value = (hash_value * 31) + *str;
        str++;
    }
    return hash_value % capacity;
}

// Create a new hash map
HashMap* hashmap_create(unsigned int capacity) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    if (!map) {
        return NULL; // Memory allocation failed
    }

    map->capacity = capacity > 0 ? capacity : INITIAL_CAPACITY;
    map->size = 0;

    // Allocate memory for the buckets array
    map->buckets = (HashMapEntry**)calloc(map->capacity, sizeof(HashMapEntry*));
    if (!map->buckets) {
        free(map); // Clean up and return NULL
        return NULL; // Memory allocation failed
    }

    return map;
}

// Insert a key-value pair into the hash map
int hashmap_put(HashMap* map, const void* key, void* value) {
    if (!map || !key) {
        return -1; // Invalid arguments
    }

    unsigned int index = hash(key, map->capacity);

    // Check if the key already exists in the bucket
    HashMapEntry* entry = map->buckets[index];
    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            // Key already exists, update the value
            entry->value = value;
            return 0; // Success
        }
        entry = entry->next;
    }

    // Key not found, create a new entry
    entry = (HashMapEntry*)malloc(sizeof(HashMapEntry));
    if (!entry) {
        return -1; // Memory allocation failed
    }
    entry->key = key;
    entry->value = value;
    entry->next = map->buckets[index];
    map->buckets[index] = entry;
    map->size++;

    return 0; // Success
}

// Get the value associated with a key from the hash map
void* hashmap_get(HashMap* map, const void* key) {
    if (!map || !key) {
        return NULL; // Invalid arguments
    }

    unsigned int index = hash(key, map->capacity);
    HashMapEntry* entry = map->buckets[index];
    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            return entry->value; // Key found, return the value
        }
        entry = entry->next;
    }

    return NULL; // Key not found
}

// Remove a key-value pair from the hash map
void hashmap_remove(HashMap* map, const void* key) {
    if (!map || !key) {
        return; // Invalid arguments
    }

    unsigned int index = hash(key, map->capacity);
    HashMapEntry* prev = NULL;
    HashMapEntry* entry = map->buckets[index];
    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            if (prev) {
                prev->next = entry->next;
            } else {
                map->buckets[index] = entry->next;
            }
            free(entry); // Free the memory allocated for the entry
            map->size--;
            return;
        }
        prev = entry;
        entry = entry->next;
    }
}

// Get the number of key-value pairs in the hash map
unsigned int hashmap_size(HashMap* map) {
    if (!map) {
        return 0; // Invalid argument
    }
    return map->size;
}

// Free the memory allocated for the hash map
void hashmap_destroy(HashMap* map, HashMapEntryFreeFn free_fn) {
    if (!map) {
        return; // Invalid argument
    }

    // Free the memory allocated for each entry in each bucket
    for (unsigned int i = 0; i < map->capacity; i++) {
        HashMapEntry* entry = map->buckets[i];
        while (entry) {
            HashMapEntry* next = entry->next;
            if (free_fn) {
                free_fn(entry); // Optionally deallocate the entry
            }
            free(entry);
            entry = next;
        }
    }

    // Free the memory allocated for the buckets array and the hash map itself
    free(map->buckets);
    free(map);
}

