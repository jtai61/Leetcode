CC = gcc
CFLAGS = -Wall -g

star: star.o
	$(CC) $(CFLAGS) $^ -o star

search: search.o
	$(CC) $(CFLAGS) $^ -o search

sorting: sorting.o
	$(CC) $(CFLAGS) $^ -o sorting

list: list.o
	$(CC) $(CFLAGS) $^ -o list

bitwise: bitwise.o
	$(CC) $(CFLAGS) $^ -o bitwise

string: string.o
	$(CC) $(CFLAGS) $^ -o string

phison: phison.o
	$(CC) $(CFLAGS) $^ -o phison

stack: stack.o
	$(CC) $(CFLAGS) $^ -o stack

queue: queue.o
	$(CC) $(CFLAGS) $^ -o queue

leetcode: leetcode.o
	$(CC) $(CFLAGS) $^ -o leetcode


%.o: %.c
	$(CC) $(CFLAGS) -c $^


clean:
	rm -f *.o star search sorting list bitwise string phison stack queue leetcode

.PHONY: clean
