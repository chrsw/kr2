# Makefile for K&R2 Section 8.7: Example: A Storage Allocator
# Made to be run from ch8/malloc dir

CC=gcc
CFLAGS=-I. -Wall -Wextra -Wpedantic
CPPFLAGS=-I.
RM=rm

ch8_malloc: main_malloc.c ch8_malloc.c ch8_malloc.h
	$(CC) -o ch8_malloc main_malloc.c ch8_malloc.c

ch8_calloc: main_calloc.c ch8_calloc.c ch8_calloc.h
	$(CC) -o ch8_calloc main_calloc.c ch8_calloc.c

ch8_calloc2: main_calloc.c ch8_calloc_2.c ch8_calloc.h
	$(CC) -o ch8_calloc2 main_calloc.c ch8_calloc_2.c

all: ch8_malloc ch8_calloc ch8_calloc2

# Remove all object files and executables
.PHONY: clean
clean:
	-$(RM) *.o ch8_calloc ch8_calloc2 ch8_malloc 2> /dev/null || echo > /dev/null

# Remove object files only
.PHONY: clobber
clobber:
	-$(RM) *.o 2> /dev/null || echo > /dev/null
