/* vim:ts=4:sw=4:et:so=10:
 *
 * ch5_strcpy2.c
 *      Copy string from source to destination. 2nd chapter 5 version.
 *
 * Description:
 *      Excerpt from chapter 5. This chapter contains a few different
 *      versions of this function.
 *
 * Input:
 *      Source and destination strings.
 *
 * Returns:
 *      N/A. Standard library version returns destination string.
 *
 * Build:
 *      $ gcc -Wall -c ch5_strcpy2.c
 *
 */

/* strcpy: copy t to s; pointer version 1 */
void ch5_strcpy2(char *s, char *t) {
   
    while ((*s = *t) != '\0')
        s++;
        t++;
}
