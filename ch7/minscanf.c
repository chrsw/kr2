/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * minscanf.c
 *      Private version of scanf.c. Solution for Exercise 7.4.
 *
 * Description:
 *      Exercise 7-4: Write a private version of scanf() analogous to
 *      minprintf() from the previous section. See minprintf.c in this
 *      directory for what that entails.
 *
 *      scanf() is described in Section 7.4. Here are the key points
 *      - converts stdin input according to 'format'
 *      - stops when the input fails to match 'format'
 *      - stops on EOF
 *      - all arguments after 'format' must be pointers
 *      - returns number of arguments successfully converted
 *      - only a subset of functionality is expected for this exercise
 *      - blanks and tabs are ignored
 *      + conversion specifications:
 *          - start with '%'
 *          - an optional supression character '*'
 *          - an optional max field width number
 *          - an optional h, l or L
 *          - a conversion character
 *      - literal characters in format string must match input
 *
 * Input:
 *      Format string and pointers to place data.
 *      For example, the format string can be something like:
 *      "n = %d"
 *      But the actual input that correstponds to this format string
 *      can be something like:
 *      "n = 1"
 *
 * Output:
 *      Data specified by format string and input from stdin.
 *
 * Returns:
 *      Number of objects successfully converted.
 *
 * Design:
 *      This function will need to get input and compare the input
 *      to the first argument 'format'. The first time the input
 *      stream doesn't match the 'format' parameter, the function
 *      should return with a count of how many conversions have happened
 *      so far. The conversion specifier in the 'format' string is '%'.
 *      This tells the function that the next sequence of characters
 *      on the input should be converted into the spedified data type.
 *      The data type specifier should be the character after the '%'.
 *      Initially this solution will only support 'd' and 'f' format
 *      conversion specifiers like the text example minprintf().
 * 
 * Implementation:
 *      This version just does something trivial to run: return 0 if
 *      input matches format string, 1 if no match.
 *
 * Build:
 *      $ gcc -c minscanf.c
 *      For full app build instructions, see minscanf_main.c.
 *
 * Run:
 *      See minscanf_main.c.
 *
 * Notes:
 *      For this example it is ok to actually call scanf() like minprintf()
 *      calls printf()?
 *
 */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "minscanf.h"


/* minscanf:  formatted input, chapter 7 version */
int minscanf(char *format, ...)
{
    va_list ap;
    int ival = 0;
    int i;
    int j;
    int c;
    int cnt = 0;
    char args[80];              /* argument string */
    int *ip;
    int len = strlen(format);

    va_start(ap, format);
    ip = va_arg(ap, int *);
    /* get some input and see if it matches format */
    printf("minscanf: format = %s, len = %d, val = %d\n",
             format, len, *ip);
    for (i = 0; i < len; i++) {
        c = getchar();
        printf("i = %d, c = %c, format[%d] = %c\n", i, c, i, format[i]);
        if (c != format[i] && format[i] != '%')
            break;
        if (format[i] == '%') {
             printf("minscanf: found arg\n");
             switch (format[++i]) {
             case 'd':      /* get a decimal number */
                j = 0;
                args[j++] = c;
                while ((c = getchar()) != ' ')
                    args[j++] = c;
                args[j] = '\0';
                printf("minscanf: j = %d, int arg = %s\n", j, args);
                for (j = 0; j < 80; j++)
                    ;
                printf("minscanf: orig: %d, new: %d\n", ival, atoi(args));
                *ip = atoi(args);
                //ival = va_arg(ap, int);
                cnt++;
                break;
            case 'f':       /* get a floating point number */
                break;
            default:
                fprintf(stderr, "minscanf: spec error: c = %c\n", c);
                break;
            }
        }
    }

    va_end(ap);
    return cnt;

}

