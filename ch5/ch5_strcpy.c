/* vim:ts=4:sw=4:et:so=10:
 *
 * ch5_strcpy.c
 *      Copy string from source to destination. 1st chapter 5 version.
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
 *      $ gcc -Wall -c ch5_strcpy.c
 *
 */

/* strcpy: copy t to s; array subscfript version */
void ch5_strcpy(char *s, char *t) {
   
    int i = 0; 

    while ((s[i] = t[i]) != '\0')
        i++;
}
