#include "bubble.h"
#include "sorting.h"
#include <stdbool.h>

void bubble_sort(int *arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    int j = size - 1;
    while (j > i) {
      if (compare(arr[j], arr[j - 1])) {
        swap(&arr[j], &arr[j - 1]);
      }
      j--;
    }
  }
  return;
}
