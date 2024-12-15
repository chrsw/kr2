/*
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
#include <stdio.h>

void expand(char s1[], char s2[]);

/* expand the simple case of '.-.' where . is any letter */
void expand(char s1[], char s2[]) {

    char start;
    char end;
    char c;
    int i = 0;
   
    /* stop if there are no chars to expand */ 
    if (strchr(s1,'-')) {
        if (s1[0] == '-') {
            s2[0] = (char)'-';
            i++;
        }
    }
    else {
        printf("expand: no range operator found\n"); 
        s2[0] = '\0';
        return;
    }

    /* asume the format m-n, where m < n and both are printable characters */
    start = s1[0+i];
    end = s1[2+i];

    for (c = start; c <= end; c++)      /* walk through every letter between */
       s2[i++] = c;                     /* start and end chars inclusive */
                                        /* copying every char to the destin- */
                                        /* ation string. */
    if (s1[strlen(s1)-1] == '-') {      /* look for training - */
       s2[i++] = (char)'-';
    }
    s2[i] = '\0';

}
