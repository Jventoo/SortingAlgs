CFLAGS =-Wall -Wextra -Werror -Wpedantic -std=c99
CC=clang $(CFLAGS)
OBJECTS = sorting.o bubble.o shell.o quick.o binary.o
EXECBIN = sorting

.PHONY: all
all: $(EXECBIN)

$(EXECBIN):$(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECBIN)

sorting.o: sorting.c sorting.h bubble.h shell.h quick.h binary.h
	$(CC) -c sorting.c

bubble.o: bubble.c bubble.h sorting.h
	$(CC) -c bubble.c

shell.o: shell.c shell.h sorting.h
	$(CC) -c shell.c

quick.o: quick.c quick.h sorting.h
	$(CC) -c quick.c

binary.o: binary.c binary.h sorting.h
	$(CC) -c binary.c

.PHONY: clean
clean:
	rm -f $(EXECBIN) *.o

.PHONY: valgrind
valgrind:
	make clean; make; valgrind ./$(EXECBIN) -A

.PHONY: infer
infer:
	make clean; infer-capture -- make; infer-analyze -- make
