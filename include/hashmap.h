// hashmap.h
#ifndef HASHMAP_H
#define HASHMAP_H

// Hash map entry structure
typedef struct HashMapEntry {
    const void* key;
    void* value;
    struct HashMapEntry* next;  // Pointer to the next entry (for separate chaining)
} HashMapEntry;

// Hash map data structure
typedef struct HashMap {
    unsigned int capacity;
    unsigned int size;
    HashMapEntry** buckets;
} HashMap;

// Function pointer type for hash map entry deallocation
typedef void (*HashMapEntryFreeFn)(HashMapEntry*);

// Create a new hash map
HashMap* hashmap_create(unsigned int capacity);

// Insert a key-value pair into the hash map
int hashmap_put(HashMap* map, const void* key, void* value);

// Get the value associated with a key from the hash map
void* hashmap_get(HashMap* map, const void* key);

// Remove a key-value pair from the hash map
void hashmap_remove(HashMap* map, const void* key);

// Get the number of key-value pairs in the hash map
unsigned int hashmap_size(HashMap* map);

// Free the memory allocated for the hash map
void hashmap_destroy(HashMap* map, HashMapEntryFreeFn free_fn);

#endif /* HASHMAP_H */

