/*
 * cat2.c
 *      cat: concatenate files, version 2
 *
 * Description:
 *      Copied from Chapter 7.6 of K&R2.
 *
 * Input:
 *      List of 2 files. 
 *
 * Other info:
 * Returns, build, notes, etc. 
 * 
 *
 */

#include <stdio.h>
#include <stdlib.h>

void filecopy(FILE *, FILE *);


/* concatenate files */
int main(int argc, char *argv[])
{
    FILE *fp;
    char *prog = argv[0];               /* program name for errors */ 

    if (argc == 1)                      /* no args: copy standard input */
        filecopy(stdin, stdout);
    else                                /* iterate over input files */
        while (--argc > 0)              /* open open file, write to stdout */
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);

            } else {                    /* file opened successfully */
                filecopy(fp, stdout);
                fclose(fp);
            }
    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
   exit (0);
}


/* filecopy: copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp)
{
    int c;
    
    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}

