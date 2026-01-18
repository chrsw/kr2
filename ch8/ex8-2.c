/*
 * ex8-2.c
 *      Solution for Exercise 8-2.
 *
 * Description:
 *      Rewrite fopen() and _fillbuf() with fields instead of explicit bit
 *      operations. Compare code size and execution speed.
 *
 * Design:
 *      ch8_fopen() and _fillbuf() use a definition of FILE that has a 
 *      'flags' field where file status is in encoded in an 'int'.
 *      See ch8_stdio.h for how this is done, based on the text.
 *      The exercise needs to implement the FILE definition with bit fields
 *      instead of an enum. In theory, this should be slower than the
 *      enum implementation because of the extra operations needed to
 *      extract values from bit fields.
 *
 * 
 * Implementation:
 *      Details on how the code you're reading implements the design.
 *
 * Build:
 *      How to build this program or a build example (incl make targets).
 *
 * Run:
 *      An example of how this program should be run.
 *
 * Notes:
 *      Helpful information for anyone to have who is maintaining this code.
 *
 */

#include <stdio.h>

int main(int argc, char *argv[])
{

    return 0;
}
