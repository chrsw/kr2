/*
 * ex8-1.c
 *      Rewrite 'cat' to use read(), write(), open() and close().
 *      
 *
 * Description:
 *      The original 'cat' uses getc(), putc(), fopen(), fclose(). 
 *      This version should use read(), write(), open(), close() instead.
 *
 * Input:
 *      List of input files.
 *
 * Build:
 *      $ gcc -o ex8-1 ex8-1.c
 * 
 * Run:
 *      $ ./ex8-1 test7.txt test8.txt
 *
 */

#include <unistd.h>             /* for the low level file I/O instead */
#include <sys/types.h>          /* of the standard library calls */
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>

int main(int argc, char *argv[])
{
    
    int fd = 0;
    int n;
    char buf[BUFSIZ];
    char *prog = argv[0];       /* save the program name because the */
                                /* argv pointer will move */ 
    int c = argc;
    if (argc == 1) {            /* no args: copy standard input */
        while ((n = read(0, buf, BUFSIZ)) > 0)
            write(1, buf, n);
    } else {
        while ( --argc > 0) {   /* for every file in the argument list */
            //printf("%s: argv[%d]: %s\n", prog, (c-argc), argv[c-argc]);
            fd = open(argv[c-argc], O_RDONLY, 0);
            n = read(fd, buf, BUFSIZ);
            write (1, buf, n);
        }
    }
   
    if (fd > 2) close(fd);      /* close any file still open */
    return 0;
}

