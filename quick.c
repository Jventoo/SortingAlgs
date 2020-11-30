#include "quick.h"
#include "sorting.h"
#include <stdbool.h>

//
// Partitions array into halves less than and greater than the pivot.
// The pivot is the leftmost element in this implementation.
//
// arr:     Array to partition
// left:    Leftmost value (pivot)
// right:   Rightmost value (end of partition range)
//
static int partition(int *arr, int left, int right);

//
// Recursively sorts an array using a partition helper function.
// O(nlogn) complexity.
//
// arr:     Array to sort
// left:    Leftmost bound to sort
// right:   Rightmost bound to sort
//
static void sort(int *arr, int left, int right);

static int partition(int *arr, int left, int right) {
  int pivot = arr[left];
  int lo = left + 1;
  int hi = right;

  while (true) {
    while (lo <= hi && compare(pivot - 1, arr[hi])) {
      hi--;
    }
    while (lo <= hi && compare(arr[lo] - 1, pivot)) {
      lo++;
    }

    if (lo <= hi) {
      swap(&arr[lo], &arr[hi]);
    } else {
      break;
    }
  }

  swap(&arr[left], &arr[hi]);
  return hi;
}

static void sort(int *arr, int left, int right) {
  if (left < right) {
    int index = partition(arr, left, right);
    sort(arr, left, index - 1);
    sort(arr, index + 1, right);
  }
  return;
}

void quick_sort(int *arr, int size) {
  sort(arr, 0, size - 1);
  return;
}
