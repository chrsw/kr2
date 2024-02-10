/* vim:ts=4:sw=4:et:so=10:
 *
 * ch8_fclose_main.c
 *      Test fclose() and fflush() from Exercise 8-3.
 *      
 *      An input file with a hard coded path is opened for reading. An output
 *      file also with a hard coded path is opened for writing. The length
 *      of the input file is larger than the length of a file's buffer.
 *      
 *      The entire input file is read into a statically allocated buffer.
 *      The application buffer is written to the file's buffer, the file's
 *      buffer is eventually filled up then more data is written to the file
 *      buffer.
 *
 *      When then file is closed with fclose(), the remaining data in the
 *      file's buffer is written out to the file with fflush(), called from
 *      within fclose().
 *
 *      No data is written to standard out in this version. Input file must
 *      be smaller than the length of the statically allocated buffer.
 *
 * Build:
 *      $ gcc -o ch8_fclose_main ch8_fopen.c fclose.c fflush.c flushbuf.c \
 *      ch8_fillbuf.c ch8_fclose_main.c
 *
 * Run:
 *      $ ./ch8_fclose_main
 *      $ cat ch8_fclose_write_test.txt
 *
 * TODO:
 *      Implement better error handling.
 *
 */

#include <string.h>
#include "ch8_stdio.h"

int fflush(FILE *);
int fclose(FILE *);
FILE *ch8_fopen(char *name, char *mode);

FILE _iob[OPEN_MAX] = {       
    {0, (char *)0, (char *)0, _READ, 0 },               /* stdin */
    {0, (char *)0, (char *)0, _WRITE, 1 },              /* stdout */
    {0, (char *)0, (char *)0, _WRITE | _UNBUF, 2 }      /* stderr */
};

char buf[100];

int main(void) {
    
    int i = 0;
    FILE *r;
    FILE *w;
    char c;
    int len;

    r = ch8_fopen("ch8_fclose_test.txt", "r");
    w = ch8_fopen("ch8_fclose_write_test.txt", "w");
    if (r == NULL || w == NULL )
        return 1;

    while (((c = getc(r)) != EOF) && (i < 100))
        buf[i++] = c;
    buf[i] = '\0';
    len = strlen(buf);

    i = 0;
    while (i <= len)
        putc(buf[i++], w);

    fclose(r);
    fclose(w);

    return 0;
}
