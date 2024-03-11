/* vim:ts=4:sw=4:et:so=10:ls=2:
 *      
 * finfo.c
 *      Show file information as retured by stat().
 *
 * Description:
 *      Part of the solution to Exercise 8-5.
 *      Show file name, mode, owner and modifcation time.
 * 
 * Input:
 *      Optional directory name.
 *
 * Build:
 *      $ gcc -c finfo.c
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


/* finfo:  print stat info from file "name" */
void finfo(char *name)
{
    struct stat stbuf;

    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "finfo: can't access %s\n", name);
        return;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, finfo);
    /* print file name, mode, owner and modifcation time */
    printf("%14s\t%lo\t%ld\t%s", name, (unsigned long)stbuf.st_mode, 
        (long)stbuf.st_uid, ctime(&stbuf.st_mtime));
}