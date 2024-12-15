/*
 * readdir.c
 *      Read directory entries in sequence.
 *
 * Description:
 *      Excerpt from Chpater 8, exercise 6.
 *
 * Input:
 *      Describe the expected input.
 *
 * Output:
 *      What output does this program generate? stdout, stderr, files, etc.
 *
 * Design:
 *      Details about the design, theory and options taken for the
 *      implemented solution.
 *
 */

#include <stdio.h>
#include <string.h>
#include "syscalls.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/dir.h>
//#include "dirent.h"

#ifndef NAME_MAX
#define NAME_MAX 14
#endif

#define DIRSIZ 14

typedef struct {
    long ino;
    char name[NAME_MAX+1];
} ch8_Dirent;

typedef struct {
    int fd;
    ch8_Dirent d;
} ch8_DIR;

ch8_Dirent *ch8_readdir(ch8_DIR *dp);

/* readdir:  read directory entries in sequence */
ch8_Dirent *ch8_readdir(ch8_DIR *dp)
{

    struct direct dirbuf;       /* local directory structure */
    static ch8_Dirent d;            /* return portable structure */

    while (read(dp->fd, (char *)&dirbuf, sizeof(dirbuf)) 
                    == sizeof(dirbuf)) {
        if (dirbuf.d_ino == 0) /* slot not in use */
            continue;
        d.ino = dirbuf.d_ino;
        strncpy(d.name, dirbuf.d_name, DIRSIZ);
        d.name[BUFSIZ] = '\0';      /* ensure termination */
        return &d;
    }



    return NULL;

}
