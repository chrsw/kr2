/* vim:ts=4:sw=4:et:so=10:
 *
 * expr.c
 *      RPN calculator using command line instead of standard input.
 *
 * Description:
 *      Use an array built from the command line instead of standard input.
 *
 * Build:
 *      $ gcc -o rpn_main rpn_main.c
 * 
 * Input:
 *      One RPN calculation per line from stdin, e.g.:
 *      1 2 + 4 5 + *
 *
 * Output:
 *      Result of each line-based calculator input, e.g.:
 *              -9
 * Test:
 *     $ ./expr 1 2 +
 *
 */

/* includes */
#include <stdio.h>                      /* includes EOF */
#include <stdlib.h>                     /* for atof() */
#include <ctype.h>                      /* isdigit(), etc */
#include <string.h>

/* defines */
#define MAXOP 100                       /* max size of operand or operator */
#define NUMBER '0'                      /* signal that a number was found */
#define MAXVAL 100                      /* maximum depth of stack */
#define BUFSIZE 100                     /* BUFSIZ defined in stdio */

/* function definitions for main, getop */
int getch(void);
void ungetch(int c);
int getop(char s[]);
void push(double);
double pop(void);

/* external variables for getch() and ungetch() */
char buf[BUFSIZE];                              /* buffer for ungetch() */
int bufp = 0;                                   /* next free position in buf */
char *gp;

/* reverse polish calculator program entry here */
int main(int argc, char *argv[]) {

    int type;
    double op2;
    char s[MAXOP];
    int i = 0;

    char *p = (char *)malloc(BUFSIZE);
    p[0] = '\0';

    ++argv;                                 /* ignore the command name */

    while (--argc > 0) {                    /* copy each command line arg */
        strcat(p, *argv++);                 /* to the end of array */
        strcat(p, " ");
    }
    p[strlen(p)-1] = '\n';
    printf("expr: input: %s\n", p);
    gp = p;
    while ((type = getop(s)) != '\0' ){
        printf("main: %d\n", i++);
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    fprintf(stderr, "error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                fprintf(stderr, "error: unknown command %s\n", s);
                break;
        }

    }

    return 0;
}

int getop(char s[]) {

    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;                               /* not a number */
    i = 0;
    if (isdigit(c))                             /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')                               /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    printf("getop: c: %d\n", c);
    printf("getop: s: %s\n", s);
    return NUMBER;
}

/* external variables for push() and pop() */
int sp = 0;                                     /* next free stack position */
double val[MAXVAL];                             /* value stack */

/* push: push f onto value stack */
void push(double f) {

    if (sp < MAXVAL)
        val[sp++] = f;
    else
        fprintf(stderr, "error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop() {
    
    if (sp > 0)
        return val[--sp];
    else {
        fprintf(stderr, "error: stack empty\n");
        return 0.0;
    }
        
    return 0;
}


/* get a (possibly pushed back) character */
int getch(void) {

    //return (bufp > 0) ? buf[--bufp] : getchar();
    return (bufp > 0) ? buf[--bufp] : *gp++;
    //printf("getch: ");
    //return buf[bufp++];
}

/* push character back on input */
void ungetch(int c) {

    if (bufp >= BUFSIZE)
        fprintf(stderr, "ungetch: too many characters\n");
    else
        buf[bufp++] = c; 
}
