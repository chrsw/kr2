/* vim:ts=4:sw=4:et:so=10:ls=2:
 *      
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
    time_t mtime;

    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, ftime);
    mtime = stbuf.st_mtime;
    printf("%20s\t\t%s", name, asctime(gmtime(&mtime)));
}
