/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * opendir.c
 *      Open a directory for readdir() calls.
 *
 * Description:
 *      As-is from Chapter 8, Section 6: Example - Listing Directories
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
DIR *opendir(char *dirname)
{
    int fd;
    struct stat stbuf;
    DIR *dp;

    if ((fd = open(dirname, O_RDONLY, 0)) == -1
     || fstat(fd, &stbuf) == -1
     || (stbuf.st_mode & S_IFMT) != S_IFDIR
     || (dp = (DIR *)malloc(sizeof(DIR))) == NULL)
        return NULL;
    dp->fd = fd;
    return dp; 
}
