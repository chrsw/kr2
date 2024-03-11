/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * dirwalk.c
 *      dirwalk() as written in Section 8.6.
 *
 * Description:
 *      Apply a function to all files in a directory dynamically.
 *      Modified to run on Ubuntu Linux 20.04.
 *
 * Input:
 *      Directory to process, function pointer to run.
 *
 * Design:
 *      Details about the design, theory and options taken for the
 *      implemented solution.
 * 
 * Implementation:
 *      Details on how the code you're reading implements the design.
 *
 * Build:
 *      $ gcc -c dirwalk.c
 *
 */

#include <string.h>
#include <stdio.h>
#include <dirent.h>


#define MAX_PATH 1024

/* dirwalk:  apply fcn to all files in dir */
void dirwalk(char *dir, void(*fcn)(char *))
{
    char name[MAX_PATH];
    struct dirent *dp;
    DIR *dfd;

    if ((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }
    while ((dp = readdir(dfd)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0
         || strcmp(dp->d_name, "..") == 0)
            continue;               /* skip self and parent */
        if (strlen(dir)+strlen(dp->d_name)+2 > sizeof(name))
            fprintf(stderr, "dirwalk: name %s/%s too long\n",
                dir, dp->d_name);
        else {
            sprintf(name, "%s/%s", dir, dp->d_name);
            (*fcn)(name);
        }
    }
    closedir(dfd);
}
