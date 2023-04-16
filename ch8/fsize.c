/* vim:ts=4:sw=4:et:
 *
 * fsize.c
 *      Print the size of files.
 *
 * Description:
 *      Excerpted from K&R2 chapter 8, section 6.
 *      Minor modifications to run without "syscalls.h".
 *
 * Build: 
 *  $ gcc -o fsize dirwalk.c fsize.c
 */


#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/dir.h>
#include <dirent.h>
#include "dirwalk.h"

void fsize(char *);

/* print file sizes */
int main(int argc, char *argv[])
{
    if (argc == 1)                      /* default: current directory */
        fsize(".");
    else
        while (--argc > 0)              /* run on every dir passed in */
            fsize(*++argv);             /* by command line */
    return 0;
}


/* fsize: print the size of file "name" */
void fsize(char *name) {

    struct stat stbuf;

    if (stat(name, &stbuf) == -1) {     /* pull file stat info into stbuf */
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)        /* ensure this is a dir */
        dirwalk(name, fsize);
    /* size is printed in number with 8 digith width */
    printf("%8ld %s\n", stbuf.st_size, name);

}


