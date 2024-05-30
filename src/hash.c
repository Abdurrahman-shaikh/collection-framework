#include "../include/hash.h"

// Implementation of a simple hash function
unsigned int hash(const char* key) {
    unsigned int hash_value = 0;

    // Hash calculation loop
    while (*key) {
        hash_value = (hash_value * 31) + *key;
        key++;
    }

    return hash_value;
}

