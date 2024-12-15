/*
 * ex4-13.c
 *     Write a recursive version of the function reverse(s), which reverses
 *     the string s in place. 
 *
 * Description:
 *      Build: gcc -DRECURSE_MAIN -o ex4-13 ex4-13.c
 *
 * Input:
 *
 *      N/A (hard coded)
 */


#include <string.h>
#include <stdio.h>

void rreverse(char s[], int i, int j);


#ifdef REVERSE_MAIN
int main(void) {

    char s[] = "now, for a much longer string to make sure this program "
               "will still work for various input string lengths. There "
               "should be plenty of stack memory for this type of "
               "operation... but we'll see...!\n"
               "just keep repeating this same line over and over ... "
               "just keep repeating this same line over and over ... "
               "just keep repeating this same line over and over ... "
               "just keep repeating this same line over and over ... "
               "just keep repeating this same line over and over ... "
               "just keep repeating this same line over and over ... "
               "just keep repeating this same line over and over ... "
               "just keep repeating this same line over and over ... "
               "just keep repeating this same line over and over ... ";
    printf("original s: %s\n", s);
    rreverse(s, 0, strlen(s)-1);
    printf("reversed s: %s\n", s);
    return 0;
}
#endif


/* reverse:	reverse string s in place */
void rreverse(char s[], int i, int j) {
	
	int c;
    int start = i, end = j;

    if ((start >= end))
        return;
    else {
        c = s[start];
        s[start] = s[end];
        s[end] = c;
        rreverse(s, ++start, --end);	
    }

}
