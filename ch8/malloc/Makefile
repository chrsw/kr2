# Makefile for K&R2 Chapter 8


ch8_malloc: main_malloc.c ch8_malloc.c ch8_malloc.h
	$(CC) -Wall -Wextra -Wpedantic -o ch8_malloc main_malloc.c ch8_malloc.c\
		ch8_malloc.h

ch8_calloc: main_calloc.c ch8_calloc.c ch8_calloc.h
	$(CC) -Wall -Wextra -Wpedantic -o ch8_calloc main_calloc.c ch8_calloc.c

ch8_calloc2: main_calloc.c ch8_calloc_2.c ch8_calloc.h
	$(CC) -Wall -Wextra -Wpedantic -o ch8_calloc2 main_calloc.c ch8_calloc_2.c

clean:
	rm ch8_calloc ch8_calloc2 ch8_malloc