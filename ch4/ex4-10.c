/* vim:ts=4:sw=4:et:so=10:
 *
 * ex4-10.c
 *      Revise the calculator to use getline() instead of getch and
 *      ungetch().
 *
 * Description:
 *      getline() reads an entire line of input. Each calculator command file
 *      (e.g. rpn_test.txt) will contain a calculation on a single line.
 *      getline() is defined in the Standard Library in stdio.h. But the book
 *      also defines a few different versions of getline(), two in chapter 1,
 *      an updated version in chapter 4 and a version that uses fgets() in
 *      chapter 7. Instead of using the Standard version, the version from
 *      chapter 4 will be defined.
 *      This version is built off ex4-6.
 *
 * Build:
 *      $ gcc -o rpn_ex4-10 ex4-10.c -lm
 *
 * Test:
 *     $ ./rpn_ex4-10 < rpn_test.txt
 *
 */

/* includes */
#include <stdio.h>                      /* includes EOF */
#include <stdlib.h>                     /* for atof() */
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

/* defines */
#define MAXOP 100                       /* max size of operand or operator */
#define NUMBER '0'                      /* signal that a number was found */
#define MAXVAL 100                      /* maximum depth of val stack */
#define BUFSIZE 100                     /* BUFSIZ already defined */
#define MAXLINE 80                      /* max length of one RPM command */ 

/* function definitions for main */
int getop(char s[]);
void push(double);
double pop(void);
int cpl_getline(char line[], int lim);

/* external variables for push() and pop() */
int sp = 0;                                     /* next free stack position */
double val[MAXVAL];                             /* value stack */

double vars[26];                                /* array of vars */
bool used_vars[26];                             /* var tracking */
double last_print = 0.0;                        /* last printed value */
char line[MAXLINE];                             /* for using getline() */
unsigned int j;
unsigned int safety = 0;
bool b_flag = true;

/* reverse polish calculator program entry here */
int main(void) {

    int type;
    double op1, op2, temp;              /* op1, temp added for swapping */
    char s[MAXOP];

    /* for tracking single-letter variable usage */
    for (int i = 0; i < 26; i++)
        used_vars[i] = false;

    /* read a line */
    while (cpl_getline(line, MAXLINE) > 0) {
        while (b_flag) {
            type = getop(s);
            if (safety++ == 20) exit(-1);
            //printf("main: type: %c (%d)\n", (char)type, type);
            switch (type) {
                case NUMBER:
                    push(atof(s));          /* atof() supports signed strings */
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
                    op2 = (int)pop();
                    if (op2 != 0.0)
                        push(pop() / op2);
                    else
                        printf("error: zero divisor\n");
                    break;
                case '%':
                    op2 = (int)pop();       /* mod does not work on doubles */
                    if (op2 != 0.0)         /* or floats */
                        push((int)pop() % (int)op2);
                    break;
                case 'p':
                    if (sp > 0)
                                        /* print top value without popping */
                        printf("\t%.8g\n", last_print = val[sp-1]);
                    break;
                case 'd':
                    if (sp > 0 ){           /* assuming top is number */
                        op2 = pop();        /* duplicate top value */
                        push(op2);
                        push(op2);
                    }
                break;
                case '$':
                    if (sp > 1) {
                        op2 = pop();        /* use a temporary value to */
                        op1 = pop();        /* swap */
                        temp = op2;
                        op2 = op1;
                        op1 = temp;
                        push(op1);          
                        push(op2);
                }
                    break;
                case '#':
                    do {                    /* clear stack */
                    pop();               /* pop values until sp is zero */
                    } while (--sp > 0);
                    break;
                case 's':                   /* sinusoidal: sine(top) */
                    push(sin(pop()));
                    break; 
                case 'e':                   /* exponential: e ^ top */
                    push(exp(pop()));
                    break;
                case '^':                   /* power: 2nd top ^ top */
                    op2 = pop();
                    op1 = pop();
                    push(pow(op1,op2));
                    break;
                /* variables */
                case 'A' ... 'Z':                      
                    if (!used_vars[type-'A']) {
                        vars[type-'A'] = pop();
                        used_vars[type-'A'] = true;
                    }
                    else
                        push(vars[type-'A']);
                    break;
                case '?':                   /* restore last printed value */
                    push(last_print);
                    break;
                case '\n':
                    printf("\t%.8g\n", last_print = pop());          /* end of cmd line */
                    b_flag = false;
                    break;
                default:
                    printf("error: unknown command %s\n", s);
                    break;
            }

        }
        b_flag = true;
        j = 0;
    }

    return 0;
}

/* get next operator or put numeric operand in s. getline() version. */
int getop(char s[]) {

    int i, c;

    //printf("getop: line: %s", line);
    /* skip leading white space */
    while ((s[0] = c = line[j++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')    /* accept sign as input */
        return c;                               /* not a number */
    i = 0;
    if (isdigit(c) || c == '-' )                /* collect integer part */
        while (isdigit(s[++i] = c = line[j++]))
            ;
    if (c == '.')                               /* collect fraction part */
        while (isdigit(s[++i] = c = line[j++]))
            ;
    s[i] = '\0';
    //printf("getop: s: %s\n", s);
    if (line[j] == '\n'|| line[j-1] == '\n')
        return -1;
    else
        return NUMBER;
}

/* push: push f onto value stack */
void push(double f) {

    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop() {
    
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
        
    return 0;
}

/* getline() from section 4.1 */
/* getline: get line into s, return length */
int cpl_getline(char line[], int lim) {

    int c, i;
    
    i = 0;
    while (--lim > 0 && (c=getchar()) && c != EOF && c != '\n') 
        line[i++] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    //printf("getline: line: %s\n", line);
    //printf("getline: i: %d\n", i);
    if (c == EOF) {
        line[++i] = c; 
        line[++i] = '\0';
        return c;
    }
    else
        return i;

}
