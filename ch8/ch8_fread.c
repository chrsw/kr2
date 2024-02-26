/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * ch8_fread.c
 *      Chapter 8 implementation of fread().
 *
 * Description:
 *      Read data from a file (given a file pointer) to a buffer.
 *
 * Input:
 *      File pointer, buffer to read into, length of data to read.
 *
 * Returns:
 *      Number of bytes read.
 *
 * Design:
 *      This is a simple implementation of fread() for testing Chapter 8
 *      functions without needing C standard library header stdio.h.
 *
 * Build:
 *      $ gcc -Wall -Wextra -Wpedantic -c ch8_fread.c
 *
 * Run:
 *      See main driver source file.
 *
 */

#include <stddef.h>
#include <unistd.h>
#include "ch8_stdio.h"
#include "ch8_fread.h"

size_t ch8_fread(void *ptr, size_t size, size_t nmemb, FILE *fp)
{
    size_t read_sz;

    /* return error (-1) for invalid parameters */
    if (ptr == NULL || fp == NULL)
        return -1;
    if (size == 0 || nmemb == 0)
        return -1;

    /* read system call */
    /* read(int fd, void *buf, size_t count) */
    read_sz = read(fp->fd, ptr, size * nmemb);

    return read_sz;
}
