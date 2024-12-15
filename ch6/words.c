/*
 * words.c
 *      Summary
 *
 * Description:
 *      Related to chapter 6, exercise 1.
 *      This file includes a main() driver that shows example
 *      uses of the functions getch(), ungetch(), getword() from
 *      K&R2 chapters 4 & 6. This file does not have examples
 *      of solutions to the exercises in chapters 4 or 6.
 *
 * Input:
 *      List of words from input file:
 *      $ ./words < words.txt
 *
 * Building:
 *      $ gcc -o words words.c getch.c getword.c bgetword.c
 *
 */

#include <stdio.h>
#include <string.h>

#define WORDSIZE 80

/* External functions from getch.c and getword.c */
int getch(void);
int getchb(void);
int getword(char *word, int lim);
int getwordb(char *word, int lim);

extern char buf[BUFSIZ];
extern int bufp;
//char lbuf[BUFSIZ];
size_t flen;

int main(int argc, char *argv[])
{
    int c;
    char word[WORDSIZE];
    FILE *f = fopen("words.txt", "r");
    (void)argc;
    (void)argv;
    
    memset(word, '0', sizeof(word));
    
    if (!f)
        return 1;
    flen = fread(buf, sizeof(word), BUFSIZ, f);     /* copy file contents */
                                                    /* into buffer */

    buf[flen++] = '\0';                             /* make sure buf */
                                                    /* has sane end*/

    printf("BUFSIZ:      %d\n", BUFSIZ);            /* system buf size */
    printf("file length: %zu\n", flen);             /* data read in */
    printf("WORDSIZE:    %d\n", WORDSIZE);
    printf("word length: %zu\n", sizeof(word));
    

    bufp = 0;
 //   while ((c = getchar()) != EOF)                  /* read all input */
 //       lbuf[bufp++] = c;                           /* into local buffer */ 

    bufp = 0;
    while ((c = getchb()) != '\0');
        ;
   
    bufp = 0;                                       /* alternate method */
    while ((c = buf[bufp++]) != '\0');              /* for getting buf */
        ;                                           /* length */
    
    printf("bufp:        %d\n", bufp);
 
    bufp = 0;

    while ((getwordb(word, BUFSIZ)) != '\0')
        printf("%s\n", word);

    printf("done!\n");

	return 0;
}
