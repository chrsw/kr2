# Makefile for K&R2 Chapter 8

fclose_main: ch8_fopen.c fclose.c fflush.c flushbuf.c\
				ch8_fillbuf.c ch8_fclose_main.c
	$(CC) -o fclose_main ch8_fopen.c fclose.c fflush.c\
				flushbuf.c  ch8_fillbuf.c ch8_fclose_main.c

clean:
	rm *.o

