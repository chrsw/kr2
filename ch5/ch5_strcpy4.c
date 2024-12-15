/*
 * ch5_strcpy4.c
 *      Copy string from source to destination. 4th chapter 5 version.
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
 *      $ gcc -Wall -c ch5_strcpy4.c
 *
 */

/* strcpy: copy t to s; pointer version 3 */
void ch5_strcpy3(char *s, char *t) {
   
    while (*s++ = *t++) 
        ;
}
