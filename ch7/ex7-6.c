/* vim:ts=4:sw=4:et:
 *
 * ex7-6.c
 *      Write a program to compare two files, printing the first line
 *      where they differ.
 *
 * Input:
 *      Two text files specified on the command line.
 *
 * Output:
 *      First line where the two files differ.
 *
 * Build:
 *      $ gcc -o ex7-6 ex7-6.c
 *
 * Usage:
 *      ./ex7-6.c test2.txt test3.txt
 *
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

    FILE *fp1;
    FILE *fp2;

    char *prog = argv[0];

    char *file1 = NULL;
    char *file2 = NULL;

    char line1[80];
    char line2[80];

    if ( argc != 3 ) {
        fprintf(stderr, "%s: error: missing input files\n", prog); 
        fprintf(stderr, "%s: usage: %s <file1> <file2>\n", prog,
                                                           prog); 
        return 1;
    }

   file1 = argv[1]; 
   file2 = argv[2]; 

    if ((fp1 = fopen(file1, "r")) == NULL) {
        fprintf(stderr, "%s: can't open %s\n", prog, file1);
        return 1;
    }

    if ((fp2 = fopen(file2, "r")) == NULL) {
        fprintf(stderr, "%s: can't open %s\n", prog, file2);
        return 1;
    }

    while ( ( fgets(line1, 80, fp1) != NULL )  && 
            ( fgets(line2, 80, fp2) != NULL ) ) {
         if (strcmp(line1, line2)) { 
            printf("%s%s", line1, line2);
            break;
         }
    }

    return 0;
}
