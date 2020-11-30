#include <getopt.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "binary.h"
#include "bubble.h"
#include "quick.h"
#include "shell.h"
#include "sorting.h"

#define OPTIONS "Absqip:r:n:"
#define CMD_SIZE 4
#define DEFAULT_AMT 100
#define DEFAULT_SEED 8222022
#define DEFAULT_SIZE 100

int comps = 0;
int moves = 0;

//
// Fills an array using random values from the supplied seed.
//
// arr:     Array to fill
// size:    Size of array to fill
// seed:    Random seed
//
static void fill_array(int *arr, int size, int seed);

int main(int argc, char **argv) {
  if (argc == 1) {
    puts("Error: no arguments supplied!");
    return -1;
  }

  int c = 0;
  int print_amt = DEFAULT_AMT, seed = DEFAULT_SEED, array_size = DEFAULT_SIZE;
  bool cmd[CMD_SIZE] = { false, false, false, false };
  bool valid_cmd = false;

  while ((c = getopt(argc, argv, OPTIONS)) != -1) {
    switch (c) {
    case 'A':
      for (int i = 0; i < CMD_SIZE; i++) {
        cmd[i] = true;
      }
      valid_cmd = true;
      break;
    case 'b':
      cmd[0] = true;
      valid_cmd = true;
      break;
    case 's':
      cmd[1] = true;
      valid_cmd = true;
      break;
    case 'q':
      cmd[2] = true;
      valid_cmd = true;
      break;
    case 'i':
      cmd[3] = true;
      valid_cmd = true;
      break;
    case 'p':
      print_amt = atoi(optarg);
      break;
    case 'r':
      seed = atoi(optarg);
      break;
    case 'n':
      array_size = atoi(optarg);
      break;
    }
  }

  if (!valid_cmd) {
    puts("Error: must supply a sort!");
    return -1;
  }

  if (print_amt > array_size) {
    print_amt = array_size;
  }

  int *array = (int *)calloc(array_size, sizeof(int));
  if (!array) {
    puts("Error: failed to allocate array!");
    return -1;
  }

  for (int i = 0; i < CMD_SIZE; i++) {
    if (cmd[i]) {
      fill_array(array, array_size, seed);
      switch (i) {
      case 0:
        puts("Bubble Sort");
        bubble_sort(array, array_size);
        break;
      case 1:
        puts("Shell Sort");
        shell_sort(array, array_size);
        break;
      case 2:
        puts("Quick Sort");
        quick_sort(array, array_size);
        break;
      case 3:
        puts("Binary Insertion Sort");
        binary_sort(array, array_size);
        break;
      }

      printf("%d elements, %d moves, %d compares\n", array_size, moves, comps);
      for (int i = 0; i < print_amt; i++) {
        printf("%13" PRIu32, array[i]);
      }
      printf("\n");

      moves = comps = 0;
    }
  }

  free(array);

  return 0;
}

bool compare(int elem1, int elem2) {
  comps++;
  return elem1 < elem2;
}

void swap(int *elem1, int *elem2) {
  moves += 3;
  int temp = *elem1;
  *elem1 = *elem2;
  *elem2 = temp;
  return;
}

static void fill_array(int *arr, int size, int seed) {
  srand(seed);
  for (int i = 0; i < size; i++) {
    int elem = rand();
    elem = elem & 0x3FFFFFFF;
    arr[i] = elem;
  }
  return;
}
