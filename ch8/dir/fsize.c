/* vim:ts=4:sw=4:et:so=10:ls=2:
 *      
 * fsize.c
 *      fsize as written in Section 8.6.
 *
 * Description:
 *      Show the size of every file in every directory recursively from the
 *      current directory or a named directory.
 *
 * Input:
 *      Optional directory name.
 *
 * Build:
 *      $ gcc -c fsize.c
 *
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>


void dirwalk(char *dir, void(*fcn)(char *));


/* fsize:  print size of file "name" */
void fsize(char *name)
{
    struct stat stbuf;

    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, fsize);
    printf("%8ld %s\n", stbuf.st_size, name);
}
