/*
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

#define LINE_LIMIT 100
int ex5_6_getline(char *s, int lim);

int main(int argc, char *argv[]) {

    char line[LINE_LIMIT];                  /* lines read in */
    unsigned int n = 10;                    /* number of lines to keep */
    char *ns;                               /* cmd line arg string */
    char **ap;                              /* pointers to arrays read in */
    char *lp;                               /* pointer to a line char array */
    unsigned int len;

    if (argc == 2) {                        /* process cmd line args */
        ns = argv[1];
        n = atoi(++ns);                     /* skip "-" switch */
    }

    /* allocate an array of pointers to point to the lines read in */ 
    /* allocate enough space for each line to save*/
    if ((ap = (char **)malloc((sizeof(ap)*n)+1)) == NULL)
        return -1;

    /* Read in every line
     * add the new recent line to the s array
     * or
     * push all other lines down s array
     * then add the new line to the end of the array 
     */
    while ((len = ex5_6_getline(line, LINE_LIMIT)) > 0) {
       
        unsigned int lc; 

        /* allocate storage for a new line including new line and '\0' */
        if ((lp = (char *)malloc(len+1)) == NULL)
            return -1;

        if (lc < n) {                       /* read in lines until max count */
            strcpy(lp, line);
            ap[lc] = lp; 
            lc++;
        } else {                            /* start removing oldest lines */
            strcpy(lp, line);
            ap[lc] = lp; 
            for (unsigned int i = 0; i < lc; i++) 
                strcpy(ap[i], ap[i+1]);
        }
    }

    /* print each line saved */
    for (unsigned int i = 0; i < n; i++)
        printf("%s", ap[i]);

    return 0;
}
