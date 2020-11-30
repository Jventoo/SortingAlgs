# Assignment 5 - Jack Vento
## The Program
Sorting is a program meant to showcase four of the most common sorting algorithms (Bubble, Shell, Quick, and Binary Insertion) and their differences through in depth runtime statistics. The arrays to be sorted are generated randomly using srand with an optionally supplied seed. See below for how to customize the program and the sorting array.

These are eight possible arguments:
* -A: Run all sorting algorithms.
* -b: Run Bubble Sort.
* -s: Run Shell Sort.
* -q: Run Quick Sort.
* -i: Run Binary Insertion Sort.
* -p n: Print the first n elements of the sorting array (default: n = 100 if not specified).
* -r s: Set the random seed for generating array elements to s (default: s = 8222022 if not specified).
* -n c: Sets the size of the sorting array to c (default: c = 100 if not specified).

Run the program using `./sorting <arguments>` after compiling. No arguments are mutually exclusive and they may be specified in any order.

## Makefile
* `make` and `make all` will compile the program to an executable named "*sequence*".
* `make clean` removes all compiler-generated files.
* `make valgrind` checks for memory management errors.
* `infer` checks for common runtime errors, though it is not always correct. Generated errors (if any) are explained below.
