# DCL Makefile

CC=gcc
CFLAGS=-I. -Wall -Wextra -Wpedantic
CPPFLAGS=-I.
DEPS=calc.h
RM=rm

# These are the objects generated by the build process
objects = getch.o dcl.o dcl_main.o gettoken.o

all: dcl

# Compile and link the DCL app
dcl: getch.o dcl.o dcl_main.o gettoken.o
	$(CC) -o dcl getch.o dcl.o dcl_main.o gettoken.o

# Run clean when asked, no matter what
.PHONY:	clean
clean:
	-$(RM) $(objects) dcl

# Remove ojbect files only
.PHONY: clobber
clobber:
	-$(RM) $(objects)	

