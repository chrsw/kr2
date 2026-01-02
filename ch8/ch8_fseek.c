/*
 * ch8_fseek.c
 *      fseek() for Solution 8-4.
 *
 * Description:
 *      Exercise 8-4: The standard library function
 *
 *          int fseek(FILE *fp, long offset, int origin)
 *
 *      is identical to lseek except that fp is a file pointer instead of a
 *      file descriptor and the return value is an int status not a position.
 *      Write fseek. Make sure that your fseek coordinates properly with the
 *      buffering done for the other functions of the library.
 *
 * Input:
 *      File pointer, offset to move, 
 *
 * Output:
 *      Operation status: success or error (-1).
 *      man pages for fseek(2) say on error -1 is returned and errno is set
 *      indicating the type of error. But for the purpose of this exercise
 *      setting of errno will be omitted.
 *
 * Design:
 *      The basic idea for ch8_fseek() is to check the arguments and call
 *      the system call lseek() and check the return value. This example will
 *      have to use the chapter 8 version of stdio.h instead of the system
 *      version.
 *
 *      Only the following offset directives will be supported:
 *      SEEK_CUR
 *      SEEK_END
 *      SEEK_SET
 * 
 * Implementation:
 *      TBD
 *
 * Build:
 *      $ gcc -c ch8_fseek.c ch8_fflush.c
 *
 * Run:
 *      TBD
 *
 * TODO:
 *      Make clear which functions are library calls and which are
 *      exercise/book versions.
 */


#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include "ch8_stdio.h"
#include "ch8_fseek.h"
#include "ch8_fflush.h"


int ch8_fseek(FILE *fp, long offset, int origin)
{
    off_t offs;
    int seeks;

    seeks = SEEK_END | SEEK_SET | SEEK_CUR;

    /* first check the file pointer is valid */
    if (fp == NULL) 
        return -1;

    if (origin & seeks) {
        offs = lseek(fp->fd, offset, origin); 
        ch8_fflush(fp);
    }
    else 
        /* unsupported origin directive */
        return -1;

    // return 'no error value'
    return 0;
}
