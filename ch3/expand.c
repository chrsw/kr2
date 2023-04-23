/* vim:ts=4:sw=4:et:so=10:
 *
 * expand.c
 *      Expand '?-?' into ?...?
 *
 * Description:
 *      This is the solution K&R2 chapter 3, exercise 3.
 *      Write a function expand() that will convert a string in compressed
 *      notation (a-z) into an expanded string containing the literal string
 *      represented by the compressed representation.
 *
 * Input:
 *      s1 string with compressed format.
 *      s2 empty string for which to store the expanded represenation.
 *
 * Returns:
 *      N/A
 *
 */

#include <string.h>

void expand(char s1[], char s2[]);

/* expand the simple case of '.-.' where . is any letter */
void expand(char s1[], char s2[]) {

    char start;
    char end;
    char c;
    int i = 0;
    
    start = s1[0];
    end = s1[2];

    for (c = start; c <= end; c++)      /* walk through every letter between */
       s2[i++] = c;                     /* start and end chars inclusive */
                                        /* copying every char to the destin- */
   s2[i] = '\0';                        /* ation string */

}
