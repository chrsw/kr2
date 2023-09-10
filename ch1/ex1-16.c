/* vim:ts=4:sw=4:et:so=10:
 *
 * ex1-16.c
 *      Print the longest input line of arbitrarily long length.
 *      From section 1.9.
 *      Used as the start of exercise 1-16.
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
 *      How to build this program or a build example (incl make targets).
 *
 * Run:
 *      An example of how this program should be run.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 1000            /* maximum input line size */

/* Standard Library (stdio.h) already defines getline() */
int sec_1_9_getline(char line[], int maxline);
void copy(char to[], char from[]);

char *l = NULL; 
char *m = NULL;

/* print longest input line */
int main(void) {

    int len;                    /* current line length */
    int max;                    /* maximum length seen so far */
    char line[MAXLINE];         /* current inpu8t line */
    char longest[MAXLINE];      /* longest line saved here */

    max = 0;
    while ((len = sec_1_9_getline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            if ((m = malloc(len)) == NULL) 
                return -2;
            else
            copy(m,l);
            copy(longest,line);
        }
        free(l);
    }

    if (max > 0) {               /* there was a line */
        //printf("%s", longest);
        printf("%s", m);
    }
    return 0;
}


/* getline: read a line into s, return length */
int sec_1_9_getline(char s[], int lim) {

    int c, i;
   
    if ((l = malloc(2)) == NULL) 
        return -2;

    strcpy(l, "");
    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
        s[i] = c;
        if ((l = realloc(l, i+2)) == NULL)
            return -2;
        else
            strcat(l, (char *)&c);
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
         if ((l = realloc(l, i)) == NULL)
            return -1;
        else
            strcat(l, "\n");
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {

    int i;
    
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

