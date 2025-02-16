/*
 * closedir.c
 *      Close a directory opened by opendir.
 *
 * Description:
 *      As-is from Chapter 8, Section 6: Example - Listing Directories
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "syscalls.h"
#include "dirent.h"


/* closedir:  close directory opened by opendir */
void ch8_closedir(ch8_DIR *dp)
{
    if (dp) {
        close(dp->fd);
        free(dp);
    }
}
