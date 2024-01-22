/* vim:ts=4:sw=4:et:so=10:
 *
 * isupper.c
 *      Simple implementation of isupper().
 *
 * Description:
 *      Part of code and solution to chapter 7, exercise 9.
 *
 * Input:
 *      One character, c.
 *
 * Returns:
 *      Non-zero if c is upper case, zero if not.
 *
 */


/* cpl_isupper:
 * cpl_ prefix to avoid conflict with Standard Library version in
 * cytpe.h
 */
int cpl_isupper(int c) {
    
    if (c < 'A' && c > 'Z')
        return 0;
    else
        return 1;
}
