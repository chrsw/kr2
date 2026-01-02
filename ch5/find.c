/*
 *  find.c
 *      find utility. From section 5.10.
 *
 * Description:
 *      Print lines that match pattern from 1st argument.
 *
 * Build:
 *      $ gcc -o find getline.c find.c
 *
 * Run:
 *      $ ./find getline < find.c
 *
 */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int sec1_9_getline(char s[], int lim);

/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[]) {

    char line[MAXLINE];
    int found = 0;

    if (argc !=2)
        printf("Usage: find pattern\n");
    else
        while (sec1_9_getline(line, MAXLINE) > 0)
            if (strstr(line, argv[1]) != NULL) {
                printf("%s", line);
                found++;
            }
    
    return found;
}
