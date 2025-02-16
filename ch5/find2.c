/*
 *  find2.c
 *      find utility. From section 5.10. 2nd version.
 *
 * Description:
 *      Print lines that match pattern from 1st argument. This version
 *      accepts command line arguments.
 *
 * Build:
 *      $ gcc -o find2 getline.c find2.c
 *
 * Run:
 *      $ ./find2 -x -n getline < find2.c
 *
 */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int sec1_9_getline(char s[], int lim);

/* find: print lines that match pattern from an argument */
int main(int argc, char *argv[]) {

    char line[MAXLINE];
    long lineno = 0;

    int c, except = 0, number = 0, found = 0;

    /* sweep through command line */
    while (--argc > 0 && (*++argv)[0] == '-')   /* sweep through cmd args */
        while (c = *++argv[0])                  /* look at first letter */
            switch (c) {                        /* of each cmd line arg */
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find2: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }
    if (argc != 1)
        printf("Usage: find2 -x -n pattern\n");
    else
        while (sec1_9_getline(line, MAXLINE) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                    printf("%ld: ", lineno);
                printf("%s", line);
                found++;
            }
        }

    return found;
}
