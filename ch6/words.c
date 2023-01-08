/* vim:ts=4:sw=4:et:
 *
 * words.c
 *      Summary
 *
 * Description:
 *      Related to chapter 6, exercise 1.
 *
 * Input:
 *
 */

#include <stdio.h>

int getch(void);
int getchb(void);
int getword(char *word, int lim);
int getwordb(char *word, int lim);

extern char buf[BUFSIZ];
extern int bufp;
size_t flen;

int main(int argc, char *argv[])
{
    int c;
    FILE *f = fopen("words.txt", "r");
    char word[80];

    for (c = 0; c < 80; c++) 
        word[c] = '0';
    
    if (!f)
        return 1;
    flen = fread(buf, sizeof(char), BUFSIZ, f);     /* copy file contents */
                                                    /* into buffer */

    buf[flen++] = '\0';                             /* make sure buf */
                                                    /* has sane end*/

    printf("BUFSIZ:      %d\n", BUFSIZ);            /* system buf size */
    printf("file length: %zu\n", flen);             /* data read in */
    
    while (c = getchar() != EOF)
        ;
    bufp = 0;
    while (c = getchb() != '\0');
        ;
   
    bufp = 0;
    while (c = buf[bufp++] != '\0');
        ;
    
    printf("bufp:        %d\n", bufp);
 
    bufp = 0;

    while (getwordb(word, BUFSIZ) != '\0')
        printf("%s\n", word);

    printf("done!\n");

	return 0;
}
