/* vim:ts=4:sw=4:et:so=10:
 *
 * ch7_getline.c
 *      Chapter 7 version of getline().
 *
 * Description:
 *      Read a line, return the length of the line read.
 *      Use the standar library function fgets().
 *
 * Input:
 *      Describe the expected input.
 *
 * Output:
 *      What output does this program generate? stdout, stderr, files, etc.
 *
 * Build:
 *      $ gcc -c ch7_getline.c
 *
 */

#include <stdio.h>
#include <string.h>

int ch7_getline(char *line, int max) {
   
    if (fgets(line, max, stdin) == NULL)
        return 0;
    else
        return strlen(line);
}
