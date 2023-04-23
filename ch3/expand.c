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

/*
 * Take a string s1 which must contain the compact range
 * operator '-'. (TODO: find the actual name for this symbol in this conext).
 * This will be exercise will be completed in parts, starting with this
 * function expand1() which will only return silently if the string s1
 * contains the '-' character in s1. If there is no '-' character in s1,
 * s2 will be set to NULL. s1 cannot be NULL.
 */
void expand(char s1[], char s2[]) {

    if (strchr((const char *)s1, '-'))
        strcpy(s2,"compacted");
    else
        s2 = NULL;

}
