/* vim:ts=4:sw=4:et:so=10:
 *
 * calc.h
 *
 */

void push(double);
double pop(void);
int gp(void);
int getop(char []);
int getch(void);
void ungetch(int c);
void usage(void);


#define BUFSIZE 100		/* BUFSIZ already defined by standard lib */
#define NUMBER '0'
#define MAXVAL 100
#define MAXOP 100
#define MAXVARS 4      /* W-Z upper case letters to store vars */
