/*
 * ll_cp.c
 *      Example of low level copy using syscalls instead of std lib functions.
 *
 * Description:
 *      Rewrite of a file copy program from chpater 1.
 *      Taken from K&R2 Chpater 8, section 2 Low Level I/O - Read and Write
 *
 * Input:
 *      Anything on standard input.
 *
 * Output:
 *      All output sent to standard output.
 *
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)      /* copy input to output */
{
    char buf[BUFSIZ];
    int n;

    while ((n = read(0, buf, BUFSIZ)) > 0)
        write(1, buf, n);

    return 0;
}
