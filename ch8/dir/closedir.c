/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
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
void closedir(DIR *dp)
{
    if (dp) {
        close(dp->fd);
        free(dp);
    }
}
