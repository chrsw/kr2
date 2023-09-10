/* vim:ts=4:sw=4:et:so=10:
 *
 * tail.c
 *      Print the last 10 or n lines of input. Solution for exercise 5-13.
 *
 * Description:
 *      Problem description from text. Chapter 5, exercise 13:
 *      Write the program `tail` which prints the last n lines of its input.
 *      By default, n is set to 10, but it can be changed by an optional
 *      argument so that
 *
 *      $ tail -n
 *
 *      prints the last n lines instead of the last 10.
 *
 * Input:
 *      Plain text.
 *
 * Output:
 *      Last 10 or n lines of input.
 *
 * Build:
 *      $ gcc -Wall -Wextra -Wpedantic -o tail ex5-6_getline.c tail.c
 *
 * Run:
 *      $ ./tail < tail_test.txt
 *      $ ./tail -5 < tail_test.txt
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ex5_6_getline(char *s, int lim);

const int limit = 100;

int main(int argc, char *argv[]) {

    char line[limit];
    int lc = 0;
    int i = 0;
    int n = 10;
    char *ns;
    char **ap;
    char *lp;
    int len;

    if (argc == 2) {
        ns = argv[1];
        n = atoi(++ns);
    }

    ap = (char **)malloc((sizeof(ap)*n)+1);

    // Read in every line
    // add the new recent line to the s array
    // or
    // push all other lines down s array
    // then add the new line to the end of the array
    while ((len = ex5_6_getline(line, limit)) > 0) {
        
        if ((lp = (char *)malloc(len+1)) == NULL)
            return -1;

        if (lc < n) {
            strcpy(lp, line);
            *(ap+lc) = lp; 
            lc++;
        } else {
            strcpy(lp, line);
            *(ap+lc) = lp; 
            for (i = 0; i < lc; i++) 
                strcpy(*(ap+i), *(ap+i+1));
        }
    }

    for (i = 0; i < n; i++){
        printf("%s", *(ap+i));
    }

    return 0;
}
