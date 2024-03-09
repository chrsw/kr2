/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * opendir.c
 *       Open a directory for readdir() calls.
 *
 * Description:
 *       As-is from Chapter 8, Section 6: Example - Listing Directories
 *
 *       Written for Version 7 UNIX and System V UNIX. Will this run on modern
 *       Linux?
 *       Linux might have different versions of opendir(), readdir() and
 *       closedir().
 *
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "syscalls.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "dirent.h"


/* opendir:  open a directory for readdir() calls */
ch8_DIR *ch8_opendir(char *dirname)
{
    int fd;
    struct stat stbuf;
    ch8_DIR *dp;

    if ((fd = open(dirname, O_RDONLY, 0)) == -1
     || fstat(fd, &stbuf) == -1
     || (stbuf.st_mode & S_IFMT) != S_IFDIR
     || (dp = (ch8_DIR *)malloc(sizeof(ch8_DIR))) == NULL)
        return NULL;
    dp->fd = fd;
    return dp; 
}
