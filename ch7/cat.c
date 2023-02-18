/* vim:ts=4:sw=4:et:
 *
 * cat.c
 *      cat: concatenate files, version 1
 *
 * Description:
 *      Copied from Chapter 7.5 of K&R2.
 *
 * Input:
 *      List of files.
 *
 * Other info:
 * Returns, build, notes, etc. 
 * 
 *
 */

#include <stdio.h>

void filecopy(FILE *, FILE *);


/* concatenate files */
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


/* filecopy: copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp)
{
    int c;
    
    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}

