/*
 * fileno_main.c
 *      An example of using fileno().
 *
 * Description:
 *
 * Input:
 *      Test files in current directory.
 *
 * Output:
 *      Some of the contents of the files and some of the new data written
 *      to the files.
 *
 * Build:
 *      $ gcc -o file fileno_main.c
 *
 * Run:
 *      $ ./fileno
 *
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
   
    printf("file descriptor %s: %d\n", fn1, fileno(fp1));
    printf("file descriptor %s: %d\n", fn2, fileno(fp2));
    
    fclose(fp1);
    fclose(fp2);

    return 0;
}
