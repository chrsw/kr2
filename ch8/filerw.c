/* vim:ts=4:sw=4:et:so=10:
 *
 * filerw.c
 *      An example of reading and writing to the same file.
 *
 * Description:
 *      Open a file for reading and writing. Read to it, write to it,
 *      then read from it again.
 *      Open another file, write to it, then read from it.
 *      Both files will exist before opening.
 *
 * Input:
 *      Test files in current directory.
 *
 * Output:
 *      Some of the contents of the files and some of the new data written
 *      to the files.
 *
 * Build:
 *      $ gcc -o filerw filerw.c
 *
 * Run:
 *      $ ./filerw
 *
 * TODO:
 *      Fix reading and writing to same file.
 */

#include <stdio.h>

int main(int argc, char *argv[]) {

    int c;                          // read/write chars to/from file
    int cn1, cn2;                   // file character counts 
    FILE *fp1 = NULL;               // file pointers/handlers
    FILE *fp2 = NULL;

    const char *fn1 = "test1.txt";  // file names to open
    const char *fn2 = "test2.txt";

    cn1 = cn2 = 0;

    (void)argc;                     // supress warnings
    (void)argv;
   
    // open both files, quit if error 
    if ((fp1 = fopen("test1.txt", "rw")) == NULL) {
        fprintf(stderr, "can't open test file %s\n", fn1);
        return 1;
    }

    if ((fp2 = fopen("test2.txt", "w")) == NULL) {
        fprintf(stderr, "can't open test file %s\n", fn2);
        return 1;
    }
   
    // read from file 1 
    while ((c = getc(fp1)) != EOF) {
        cn1++;
        if (cn1 < 10) putchar(c);
    }
   

    // write to file 2
    for ( c = 97; c < 107; c++)
        putc(c, fp2);

    fflush(fp2);
    // read from file 2 
    //fseek(fp2, 0L, 0);
    while ((c = getc(fp2)) != EOF) {
        cn2++;
        printf("%d: ", cn2);
        if (cn2 < 10) putchar(c);
    }
 
    if ((cn1 > 0)) printf("\n");

    return 0;
}
