/* vim:ts=4:sw=4:et:so=10:ls=2:
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
 *      Printout to standard output (terminal) of all named files on
 *      command line split into pages with centered headers at the top
 *      of each page.
 *
 * Design:
 *      Open each file listed on the command line.
 *      Print each file inserting a header into the output every page.
 *      Center the header using the length of the file name.
 *      Each page is 25 rows, including header. Fill space left on each
 *      page with blank lines.
 *
 * Build:
 *      $ gcc -o prp prp.c ch7_fgets.c ch7_getline.c
 *      - or -
 *      $ make prp
 *
 * Run:
 *      $ ./prp <file1> <file2> <file3> ... <fileN>
 *      - or -
 *      $ ./prp file* # let the shell expand list of files
 *
 * TDOO:
 *      Put file name headers on left and right side of screen.
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
    int i;
    FILE *fp;
    char fline[80];                 /* working line of every file */
    int fpos = 0;

    unsigned int curpos = 0;        /* line in page counter */

    /* print files named on command line */
    for (i = 1; i < argc; i++) {
        fp = fopen(argv[i], "r");
        if (fp != NULL) {
            fpos = 40 - strlen(argv[i])/2 + strlen(argv[i]);
            while (ch7_getline(fline, 79, fp) > 0) {
                /* print a file header every 24 lines */
                if ((curpos++ % 24) == 0)
                    printf("%*s\n", fpos, argv[i]);
                printf("%s", fline);
            }
        }
        /* start next file on new page */
        while (curpos++ < 24) printf("\n");
        curpos = 0;
        fclose(fp);
        if (i < argc-1) puts("\n");
    }

   return 0;
}
