/*
 * ch5_match.c
 *      Find all lines matching a pattern. strindex() pointer version.
 *
 * Description:
 *      Partial solution to exercise 5-6.
 *      Converting existing programs and functions from array based notation
 *      to pointer notation.
 *      Description from the text: a program to print each line of its
 *      input that contains a particular "pattern" or string of characters.
 *
 * Input:
 *      Text on standard input.
 *
 * Output:
 *      Lines that match a special pattern defined in the applicatin.
 *
 * Returns:
 *      Number of lines matched.
 *
 * Build:
 *      $ gcc -o match ch5_match.c
 *
 * Run:
 *      $ cat match_test_input.txt | ./match
 *
 */

#include <stdio.h>

#define MAXLINE 100

int ch4_getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";


/* find all lines matching pattern */
int main(int argc, char *argv[]) {
    
    char line[MAXLINE];
    int found = 0;

    while (ch4_getline(line, MAXLINE) > 0)
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }

    return found;
}


/* getline: get line into s, return length */
int ch4_getline(char s[], int lim) {

    int i, c;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}


/* strindex: return index of t in s, -1 if none. pointer version. */
int strindex(char s[], char t[]) {

    int i, j, k;
    
    for (i = 0; *(s+i) != '\0'; i++) {
        for (j=i, k=0; *(t+k)!='\0' && *(s+j)==*(t+k); j++, k++)
            ;
        if (k > 0 && *(t+k) == '\0')
            return i;
    }
    
    return -1;
}
