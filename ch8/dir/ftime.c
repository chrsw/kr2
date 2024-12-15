/*      
 * ftime.c
 *      Show file modification time.
 *
 * Description:
 *      Part of the solution to Exercise 8-5.
 *
 * Input:
 *      Optional directory name.
 *
 * Build:
 *      $ gcc -c ftime.c
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
#include <time.h>


void dirwalk(char *dir, void(*fcn)(char *));


/* ftime:  print modification time of file "name" */
void ftime(char *name)
{
    struct stat stbuf;

    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "ftime: can't access %s\n", name);
        return;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, ftime);
    printf("%20s\t\t%s", name, ctime(&stbuf.st_mtime));
}
