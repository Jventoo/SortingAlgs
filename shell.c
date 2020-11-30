#include "shell.h"
#include "sorting.h"
#include <stdbool.h>

//
// Returns gap for a specified n
//
// n:   The current gap in the shell sort
//
static int gap(int n);

static int gap(int n) {
  if (n == 1) {
    return 0; // Making final gap 0 saves from making auxillary gaps array
  }
  return (n <= 2) ? 1 : (5 * n / 11);
}

void shell_sort(int *arr, int size) {
  for (int step = gap(size); step > 0; step = gap(step)) {
    for (int i = step; i < size; i++) {
      for (int j = i; j >= step; j -= step) {
        if (compare(arr[j], arr[j - step])) {
          swap(&arr[j], &arr[j - step]);
        }
      }
    }
  }
}
