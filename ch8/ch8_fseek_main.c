/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * ch8_fseek_main.c
 *      Main driver for ch8_fseek(), Exercise 8-4.
 *
 * Description:
 *      Demonstrate the use of Exercise 8-4 by using ch8_fseek() on a test
 *      file.
 *
 * Input:
 *      
 *
 * Output:
 *      Test data added to output file.
 *
 * Design:
 *      Details about the design, theory and options taken for the
 *      implemented solution.
 * 
 * Implementation:
 *      Details on how the code you're reading implements the design.
 *
 * Build:
 *      $ gcc -o ch8_fseek_main ch8_fseek_main.c ch8_fseek.c\
 *      ch8_fopen.c fclose.c ch8_fflush.c
 *
 * Run:
 *      $ ./ch8_fseek_main
 *
 * Notes:
 *      Helpful information for anyone to have who is maintaining this code.
 *
 */

#include "ch8_stdio.h"
#include "ch8_fseek.h"

/* Three files available by default 
 * stdout, stdin, stderr 
 */
FILE _iob[OPEN_MAX] = {
    {0, (char *)0, (char *)0, _READ, 0 },               /* stdin */
    {0, (char *)0, (char *)0, _WRITE, 1 },              /* stdout */
    {0, (char *)0, (char *)0, _WRITE | _UNBUF, 2 }      /* stderr */
};

int main(int argc, char *argv[])
{

    return 0;
}
