/*
 * ex7_find.c
 *      Modify the pattern matching program of Chapter 5 to take its
 *      input from a set of named files or, if no files are named as
 *      arguments, from standard input. Should the file name be printed 
 *      when a matching line is found?
 *
 * Input:
 *      Files specified on the command line, or standard input
 *      and pattern to match
 *
 * Output:
 *      Input lines that match the pattern.
 *
 * Build:
 *      $ gcc -o ex7-find ch7_getline.c ex7_find.c
 *
 * Run:
 *      $ ./ex7-find ex7_test2.txt ex7_test.txt pattern
 *
 * TODO:
 *    Optionally restore command line options -x and -n.
 */


#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int ch7_getline(char s[], int lim, FILE *fp);

char gfiles[32][80];
FILE *gfp[32];

/* find: print lines that match pattern from an argument */
int main(int argc, char *argv[]) {

    char line[MAXLINE];
    long lineno = 0;
    char filename[80];
    FILE *fp;
    int i = 0;
    int c, except = 0, number = 0, found = 0;

    /* ignore the other command line options for now for simplicity */
    number = 1;
    except = 0;

    ++argv;
    /* get list of file names to open */
    while (--argc > 1) {
        printf("ex7_find: opening %s\n", *argv);
        gfp[i++] = fopen(*argv++, "r");
    }
    printf("files found: %d\n", i);
    if (argc != 1) {
        printf("Usage: ex7_find -x -n pattern\n");
        printf("File name to open: %s\n", filename); 
    }
    else {
        printf("Pattern to search: %s\n", *argv); 
        while (i-- > 0) {
            while (ch7_getline(line, MAXLINE, gfp[i]) > 0) {
                lineno++;
                if ((strstr(line, *argv) != NULL) != except) {
                    if (number)
                        printf("%ld: ", lineno);
                    printf("%s", line);
                    found++;
                }
            }
        }
    }
    return found;
}
