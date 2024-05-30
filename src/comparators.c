#include "../include/comparators.h"

int compareInt(const void* a, const void* b) {
    int num1 = *((int*)a);
    int num2 = *((int*)b);
    if (num1 < num2) return -1;
    else if (num1 > num2) return 1;
    else return 0;
}

