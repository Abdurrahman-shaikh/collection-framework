#ifndef COMPARATORS_H
#define COMPARATORS_H

// Comparator function type definition
typedef int (*Comparator)(const void*, const void*);

// Example comparator for integers
int compareInt(const void* a, const void* b);

#endif /* COMPARATORS_H */

