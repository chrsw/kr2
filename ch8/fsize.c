/* vim:ts=4:sw=4:et:
 *
 * fsize.c
 *      Print the size of files.
 *
 * Description:
 *      Excerpted from K&R2 chapter 8, section 6.
 *
 * Input:
 *      Describe the expected input.
 *
 * Other info:
 * Returns, build, notes, etc. 
 * 
 *
 */


#include <stdio.h>
#include <string.h>
//#include "syscalls.h"
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
        while (--argc > 0)
            fsize(*++argv);
    return 0;
}


/* fsize: print the size of file "name" */
void fsize(char *name) {

    struct stat stbuf;

    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, fsize);
    printf("%8ld %s\n", stbuf.st_size, name);

}









