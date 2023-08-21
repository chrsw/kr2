/* vim:ts=4:sw=4:et:so=10:
 *
 * fflush.c
 *      Close a stream.
 *
 * Description:
 *      Simple fclose() implementation for part of Exercise 8-3.
 *      
 *      Description from the text:
 *      
 *      Description from local man page:
 *
 * Returns:
 *      0 for succession, otherwise EOF. Not implemented errno for this
 *      version.
 *
 * Output:
 *
 * Build:
 *      $ gcc -c fclose.c
 *      $ gcc -o app fflush.c fclose.c app.c
 *
 *
 */

#include "syscalls.h"
#include "stdio.h"

int fflush(FILE *);


int fclose(FILE *fp) {

    fflush(fp);
    close(fp->fd);
    return 0;
}
