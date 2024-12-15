/*
 * ch7_getline.c
 *      Chapter 7 version of getline().
 *
 * Description:
 *      Read a line, return the length of the line read.
 *      Use the standard library function fgets().
 *
 * Build:
 *      $ gcc -c ch7_getline.c
 *      - or -
 *      $ gcc -c app ch7_getline.c app.c
 *
 */

#include <stdio.h>
#include <string.h>
#include "ch7_getline.h"

/* ch7_getline:  read a line, chapter 7 version */
int ch7_getline(char *line, int max, FILE *fp) {
   
    if (fgets(line, max, fp) == NULL)
        return 0;
    else
        return strlen(line);
}
