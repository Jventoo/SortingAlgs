#ifndef __SORTING_H__
#define __SORTING_H__

#include <stdbool.h>

//
// Compares the values of elem1 and elem2 and increments comparisons count.
// Returns true if *elem1 < *elem2.
//
// elem1:   Address of elem1
// elem2:   Address of elem2
//
bool compare(int elem1, int elem2);

//
// Swaps the values of elem1 and elem2 using a temp
// variable and increments moves count.
//
// elem1:   Address of elem1
// elem2:   Address of elem2
//
void swap(int *elem1, int *elem2);

#endif
