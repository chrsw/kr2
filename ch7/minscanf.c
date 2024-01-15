/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * minscanf.c
 *      Private version of scanf.c
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
 *
 * Output:
 *      Data specified by format string and input from stdin.
 *
 * Returns:
 *      Number of objects successfully converted.
 *
 * Design:
 *      Details about the design, theory and options taken for the
 *      implemented solution.
 * 
 * Implementation:
 *      This version just does something trivial to run: return 0 if
 *      input matches format string, 1 if no match.
 *
 * Build:
 *      See minscanf_main.c.
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
#include "minscanf.h"


/* ch7_scanf:  formatted input, chapter 7 version */
int ch7_scanf(char *format, ...)
{
    char *p;
    int ret = 0;
    for (p = format; *p; p++) {
        if (getchar() != *p)
            ret = 1;
    }

    return ret;
}
