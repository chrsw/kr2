/* vim:ts=4:sw=4:et:so=10:
 *
 * sec5-3_strlen.c
 *      strlen() from section 5.3.
 *
 * Input:
 *      Null terminated string.
 *
 * Output:
 *      Integer length of string.
 *
 * Notes:
 *      Renamed to sed5_3_strlen because strlen is already defined
 *      by the C library and by a GCC built-in.
 *
 */

int sec5_3_strlen(char *s);

/* strlen:  return lenth of string s */
int sec5_3_strlen(char *s) {

    int n;

    for (n = 0; *s != '\0'; s++)
        n++; 
    return n;
}
