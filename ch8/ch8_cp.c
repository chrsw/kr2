/* vim:ts=4:sw=4:et:so=10:
 *
 * ch8_cp.c
 *      Copy f1 to f2.
 *
 * Description:
 *      Chapter 8 version of 'cp' program.
 *
 * Input:
 *      1 file.
 *
 * Output:
 *      Copy of input file.
 *
 * Build:
 *      $ gcc -o ch8_cp ch8_cp.c
 *
 * Run:
 *      $ ./ch8_cp test_file.txt
 *
 */

#include <stdio.h>
#include <fcntl.h>
#include "syscalls.h"
#include <error.h>
#define PERMS 0666              /* RW for owner, group, others */

void ch8_error(char *, ...);

/* cp:  copy f1 to f2 */
int main(int argc, char *argv[]) {
    
    int f1, f2, n;
    char buf[BUFSIZ];

    if (argc != 3)
        ch8_error("Usage: cp from to");
    if ((f1 = open(argv[1], O_RDONLY, 0)) == -1)
        ch8_error("cp: can't open %s", argv[1]);
    if ((f2 = creat(argv[2], PERMS) == -1))
        ch8_error("cp: can't create %s, mode %03o", argv[2], PERMS);
    while (( n = read(f1, buf, BUFSIZ)) > 0)
        if (write(f2, buf, n) != n)
            ch8_error("cp: write error on file %s", argv[2]);
    return 0;
}

#include <stdarg.h>
#include <stdlib.h>

/* ch8_error:  print an error message and die */
void ch8_error(char *fmt, ...) {

    va_list args;
    
    va_start(args, fmt);
    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}

