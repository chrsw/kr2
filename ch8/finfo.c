/* vim:ts=4:sw=4:et:so=10:
 *
 * finf.c
 *      Print size of files and other file info.
 *
 * Description:
 *      Solution to K&R2 exercise chapter 8-5.
 *      Exercise text: Modify the fsize program to print the other information
 *      contained in the inode entry.
 *
 * Build: 
 *  $ gcc -o finfo dirwalk.c fsize.c
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

void finfo(char *);

/* print file sizes */
int main(int argc, char *argv[])
{
    if (argc == 1)                      /* default: current directory */
        finfo(".");
    else
        while (--argc > 0)              /* run on every dir passed in */
            finfo(*++argv);             /* by command line */
    return 0;
}


/* fsize: print the size of file "name" */
void finfo(char *name) {

    struct stat stbuf;

    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, finfo);
    printf("%4lu%8u%8ld %s\n", stbuf.st_nlink, stbuf.st_uid, stbuf.st_size, name);

}
