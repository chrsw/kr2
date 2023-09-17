/* vim:ts=4:sw=4:et:so=10:
 *
 * ex1-16.c
 *      Print the longest input line of arbitrarily long length.
 *
 * Description:
 *      Revise the main routine of the longest-line program so it will
 *      correctly print the length of aribrarily long input lines, and as
 *      much as possible of the text.
 *
 * Input:
 *      Plain text lines.
 *
 * Output:
 *      Longest line from input.
 *
 * Build:
 *      $ gcc -Wall -Wextra -Wpedantic -o ex1-16 ex1-16.c
 *
 * Run:
 *      Example:
 *      $ ./ex1-16 < ex1-16.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Standard Library (stdio.h) already defines getline() */
int ex_1_16_getline(void);
void copy(char to[], char from[]);

char *l = NULL; 
char *m = NULL;


/* print longest input line */
int main(void) {

    int len;                    /* current line length */
    int max;                    /* maximum length seen so far */

    max = 0;

    while ((len = ex_1_16_getline()) > 0) {
        if (len > max) {
            max = len;
            if ((m = malloc(len)) == NULL) 
                return -2;
            else 
                copy(m,l);
        }
        free(l);
    }

    if (max > 0)                /* there was a line */
        printf("%s", m);
    
    return 0;
}


/* getline: read a line into s, return length. 
 * Exercise 1.16 version:
 * accept arbitrarily long input lines using dynamic memory allocation
 */
int ex_1_16_getline(void) {

    int c, i;
   
    if ((l = malloc(2)) == NULL) 
        return -2;

    strcpy(l, "");
    for (i=0; (c=getchar())!=EOF && c!='\n'; ++i) {
        if ((l = realloc(l, i+2)) == NULL)
            return -2;
        else
            strcat(l, (char *)&c);
    }
    if (c == '\n') {
         if ((l = realloc(l, ++i)) == NULL)
            return -1;
        else
            strcat(l, "\n");
    } 

    return i;
}


/* copy: copy 'from' into 'to'; assume 'to' is big enough */
void copy(char to[], char from[]) {

    int i = 0;
    
    while ((to[i] = from[i]) != '\0')
        ++i;
}

