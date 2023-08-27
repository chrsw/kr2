/* vim:ts=4:sw=4:et:so=10:
 *
 * ch8_fclose_main.c
 *      Test fclose() from Exercise 8-3.
 *
 * Build:
 *      $ gcc -o ch8_fclose_main ch8_fopen.c fclose.c flushbuf.c \
 *      ch8_fillbuf.c ch8_fclose_main.c
 */

#include "stdio.h"

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

    r = ch8_fopen("ch8_fclose_test.txt", "r");
    w = ch8_fopen("ch8_fclose_write_test.txt", "w");
    if (r == NULL)
        return 1;
    if (w == NULL)
        return 1;

    while ((c = getc(r)) != EOF)
        buf[i++] = c;
    buf[i] = '\0';
    i = 0;
    while (i < 30)
        putc(buf[i++], w);

    fclose(r);
    fclose(w);
    return 0;
}
