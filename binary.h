#ifndef __BINARY_H__
#define __BINARY_H__

//
// Insertion sorts an array with help from a binary search to find
// positioning. Significantly improves comparisons required from a
// traditional insertion sort.
// O(n^2) complexity.
//
// arr:     Array to sort
// size:    Size of array to sort
//
void binary_sort(int *arr, int size);

#endif
