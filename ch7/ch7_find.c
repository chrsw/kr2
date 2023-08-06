/* vim:ts=4:sw=4:et:so=10:
 *
 *  ch7_find.c
 *      find utility. Chapter 7 version.
 *
 * Description:
 *      Print lines that match pattern from 1st argument. This version
 *      takes input from a list of files specified on the command line,
 *      or standard input if no command line arguments are given.
 *      Prints line numbers of each match as well.
 *
 * Build:
 *      $ gcc -o ch7-find ch7_getline.c ch7_find.c
 *
 * Run:
 *      $ ./ch7-find ch7_find.c getline
 *
 */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int ch7_getline(char s[], int lim, FILE *fp);

/* find: print lines that match pattern from an argument */
int main(int argc, char *argv[]) {

    char line[MAXLINE];
    long lineno = 0;
    char filename[80];
    FILE *fp;

    int c, except = 0, number = 0, found = 0;

    /* ignore the other command line options for now for simplicity */
    number = 1;
    except = 0;

    --argc;
    ++argv;
    strcpy(filename, *argv++); 
    if (argc != 2) {
        printf("Usage: ch7-find -x -n pattern\n");
        printf("File name to open: %s\n", filename); 
    }
    else {
        printf("File name to open: %s\n", filename); 
        printf("Pattern to search: %s\n", *argv); 
        fp = fopen(filename, "r");
        while (ch7_getline(line, MAXLINE, fp) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                    printf("%ld: ", lineno);
                printf("%s", line);
                found++;
            }
        }
    }
    return found;
}
