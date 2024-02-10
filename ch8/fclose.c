/* vim:ts=4:sw=4:et:so=10:
 *
 * fflush.c
 *      Close a stream.
 *
 * Description:
 *      Simple fclose() implementation for part of Exercise 8-3.
 *      
 * Returns:
 *      0, error handling not implemented. 
 *
 * Output:
 *
 * Build:
 *      $ gcc -c fclose.c
 *      - or example app -
 *      $ gcc -o app fflush.c fclose.c app.c
 *
 */

#include <stdlib.h>
#include "syscalls.h"
#include "stdio.h"

int fflush(FILE *);

int fclose(FILE *fp) {

    fflush(fp);
    if (fp->base != NULL)
        free(fp->base);
    close(fp->fd);
    return 0;
}
