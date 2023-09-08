/* vim:ts=4:sw=4:et:so=10:
 *
 * tail.c
 *      Print the last 10 or n lines of input. Exercise 5-13.
 *
 * Description:
 *      Problem description from text. Chapater 5, exercise 13:
 *      Write the program `tail` which prints the last n lines of its input.
 *      By default, n is set to 10, but it can be changed by an optional
 *      argument so that
 *
 *      $ tail -n
 *
 *      prints the last n lines.
 *
 * Input:
 *      Plain text.
 *
 * Output:
 *      Last 10 or n lines of input.
 *
 * Build:
 *
 * Run:
 *      An example of how this program should be run.
 *
 * Notes:
 *      Helpful information for anyone to have who is maintaining this code.
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ex5_6_getline(char *s, int lim);

const int limit = 100;

int main(int argc, char *argv[]) {

    char s[10][limit];
    char line[limit];
    int lc = 0;
    int i = 0;
    int n = 10;
    char *ns;

    if (argc == 2) {
        ns = argv[1];
        n = atoi(++ns);
    }

    // Read in every line
    // add the new recent line to the s array
    // or
    // push all other lines down s array
    // then add the new line to the end of the array
    while (ex5_6_getline(line, limit) > 0) {
        
        if (lc < n) {
            strcpy(s[lc++], line);
        } else {
            for (i = 0; i < n; i++) {
                strcpy(s[i],s[i+1]);
            }
            strcpy(s[lc], line);
        }
        
    }

    for (i = 1; i <= n; i++)
        printf("%s", s[i]);

    return 0;
}
