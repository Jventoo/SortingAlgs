#ifndef __QUICK_H__
#define __QUICK_H__

//
// Wrapper for quick sort that allowing for easier calling.
// Calls static helper sort() which in turn calls static partition().
//
// arr:     Array to sort
// size:    Size of the supplied array
//
void quick_sort(int *arr, int size);

#endif
