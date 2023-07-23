/* vim:ts=4:sw=4:et:so=10:
 *
 * ch5_strncpy.c
 *      Partial solution to 5-5. Write version of the library function
 *      strncpy(), which operates on at most the first n characters of
 *      their argument strings.
 *      Copy string from source to destination. 3rd chapter 5 version.
 *
 * Description:
 *      Standard library description:
 *      strcpy, strncpy - copy a string.
 *
 * Input:
 *      Source and destination strings.
 *
 * Returns:
 *      Destination string.
 *
 * Build:
 *      $ gcc -Wall -c ch5_strncpy.c
 *
 */

/* strcpy: copy t to s; pointer version 3 */
char * ch5_strncpy(char *s, char *t, int n) {
 
    int nc = n; 

    while ((*s++ = *t++) && (n-- > 0)) 
        ;
    s[nc] = '\0'; 

    return s;
}
