#include "binary.h"
#include "sorting.h"
#include <stdbool.h>

void binary_sort(int *arr, int size) {
  for (int i = 1; i < size; i++) {
    int value = arr[i];
    int left = 0;
    int right = i;

    while (left < right) {
      int mid = left + ((right - left) / 2);

      if (compare(arr[mid] - 1, value)) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    for (int j = i; j > left; j--) {
      swap(&arr[j - 1], &arr[j]);
    }
  }
  return;
}
