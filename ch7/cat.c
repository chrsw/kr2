/*
 * cat.c
 *      Concatenate files, version 1
 *
 * Description:
 *      Excerpt from Seciton 7.5 of K&R2.
 *
 * Input:
 *      List of files on command line.
 *
 *
 */

#include <stdio.h>

void filecopy(FILE *, FILE *);


/* cat:  concatenate files */
int main(int argc, char *argv[])
{
    FILE *fp;
    
    if (argc == 1) /* no args: copy standard input */
        filecopy(stdin, stdout);
    else
        while (--argc > 0)
            if ((fp = fopen(*++argv, "r")) == NULL) {
                printf("cat: can't open %s\n", *argv);
                return 1;

            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }

   return 0;
}


/* filecopy:  copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp)
{
    int c;
    
    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}

