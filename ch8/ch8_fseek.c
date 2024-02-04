/* vim:ts=4:sw=4:et:so=10:ls=2:
 *      Vim modeline for consistent editor settings across files.
 *
 * ch8_fseek.c
 *      fseek() for Solution 8-4.
 *
 * Description:
 *      Exercise 8-4: The standard library function
 *
 *          int fseek(FILE *fp, long offset, int origin)
 *
 *      is identical to lseek except that fp i sa file pointer instead of a
 *      file descriptor and the return value is an int status not a position.
 *      Write fseek. Make sure that your fseek coordinates properly with the
 *      buffering done for the other functions of the library.
 *
 * Input:
 *      File pointer, offset to move, 
 *
 * Output:
 *      Operation status: success or error type.
 *
 * Design:
 *      TBD
 * 
 * Implementation:
 *      TBD
 *
 * Build:
 *      $ gcc -c ch8_fseek.c
 *
 * Run:
 *      TBD
 *
 */


#include <stdio.h>

int ch8_fseek(FILE *fp, long offset, int origin);

int ch8_fseek(FILE *fp, long offset, int origin)
{

    return 0;
}
