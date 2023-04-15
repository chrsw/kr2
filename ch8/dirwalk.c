/* vim:ts=4:sw=4:et:
 *
 * dirwalk.c
 *      Apply a function to all fies in dir
 *
 * Description:
 *      Excerpted from K&R2 chapter 8, section 6.
 *
 *
 * $ gcc -c dirwalk.c
 *
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

#define MAX_PATH 1024

/*
 * apply fcn to all files in dir
 */
void dirwalk(char *dir, void (fcn)(char *))
{
    char name[MAX_PATH];
    struct dirent *dp;
    DIR *dfd;

    if ((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }
    
    while ((dp = readdir(dfd)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0 ||
            strcmp(dp->d_name, "..") == 0)
            continue;           /* skip self and parent */
        if (strlen(dir) + strlen(dp->d_name) + 2 > sizeof(name))
            fprintf(stderr, "dirwalk: name %s/%s too long\n",
                    dir, dp->d_name);
        else {
            sprintf(name, "%s/%s", dir, dp->d_name);
            (*fcn)(name);
        }
    }
}

