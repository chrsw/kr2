/* vim:ts=4:sw=4:et:so=10:
 *
 * ch8_fclose.c
 *      Close a stream.
 *
 * Description:
 *      Simple fclose() implementation for part of Exercise 8-3.
 *      
 * Returns:
 *      0, error handling not implemented. 
 *
 * Build:
 *      $ gcc -c ch8_fclose.c
 *      - or example app -
 *      $ gcc -o app ch8_fflush.c ch8_fclose.c app.c
 *
 */

#include <stdlib.h>
#include "syscalls.h"
#include "ch8_stdio.h"
#include "ch8_fflush.h"


int ch8_fclose(FILE *fp) {

    ch8_fflush(fp);
    if (fp->base != NULL)
        free(fp->base);
    close(fp->fd);
    return 0;
}
