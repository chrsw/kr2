/* vim:ts=4:sw=4:et:so=10:ls=2:
 *      Vim modeline for consistent editor settings across files.
 *
 * prp.c
 *      Print a set of files, starting each new one on a new page.
 *      Solution to exercise 7-8.
 *
 * Description:
 *      Exercise text:
 *      Write a program to print a set of files, starting each new one
 *      on a new page, with a title and running page count for each file.
 *
 *      Print a set of files where each file only appears on one page or
 *      This excercise basically asks the reader to write a simplified
 *      version of the unix 'pr' command.
 *
 * Input:
 *      A list of files named on the command line.
 *
 * Output:
 *      What output does this program generate? stdout, stderr, files, etc.
 *
 * Design:
 *      Details about the design, theory and options taken for the
 *      implemented solution.
 * 
 * Implementation:
 *      Details on how the code you're reading implements the design.
 *
 * Build:
 *      $ gcc -o prp prp.c
 *
 * Run:
 *      $ ./prp <file1> <file2> <file3> ... <fileN>
 *
 * Notes:
 *      Helpful information for anyone to have who is maintaining this code.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ch7_fgets.h"
#include "ch7_getline.h"

/* prp:  print a set of files, split file into unique pages */
int main(int argc, char *argv[])
{
    int i = 1;
    FILE *fp;
    char *fname;
    char fline[80];
    int flen = 0;
    int fpos = 0;
    int llen = 0;
    unsigned int curpos = 0;

    /* print command line args */
    for (i = 1; i < argc; i++) {
        printf("%s%s", argv[i], (i < argc-1) ? " " : "");
    }
    printf ("\n");

    /* open files named on command line */ 
    i = 1;
    for (i = 1; i < argc; i++) {
        fp = fopen(argv[i], "r");
        if (fp != NULL)
            printf("%s successfully opened!\n", argv[i]);
        fclose(fp);
    }

    /* print files named on command line */
    i = 1;
    for (i = 1; i < argc; i++) {
        fp = fopen(argv[i], "r");
        if (fp != NULL) {
            flen = strlen(argv[i]);
            fpos = 40 - (flen/2) + flen;
            /* print a file header every 24 lines */
            //if ((curpos++ % 24) == 0)
            //    printf("%*s\n", fpos, argv[i]);
            while (llen = ch7_getline(fline, 79, fp) > 0) {
                /* print a file header every 24 lines */
                if ((curpos++ % 24) == 0)
                    printf("%*s\n", fpos, argv[i]);
                printf("%s", fline);
            }
        }
        while (curpos++ < 24) printf("\n");
        curpos = 0;
        fclose(fp);
        if (i < argc-1)
            puts("\n");
    }

   return 0;
}
