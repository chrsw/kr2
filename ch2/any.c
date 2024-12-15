/*
 * any.c
 *      Implements the any() function. Returns the number of bytes into s1
 *      where the first match is found for any character in s2.
 *
 * Description:
 *      Write the function any(s1,s2), which returns the first location in
 *      the string s1 where any character from the string s2 occurs, or -1
 *      if s1 contains no characters from s2. (The standard library function
 *      strpbrk does the same job but returns a pointer to the location.)
 *      For K&R2 Chapter 2, Exercise 2-5. Main driver will be in a separate
 *      file, ex2-5.c
 *
 * Input:
 *      s1 input string where the search is performed
 *      s2 input string where characters from the string are searched for
 *      in s1.
 *
 * Returns:
 *      Byte or character index into s1 where the first of any character 
 *      from s2 is found.
 * 
 *
 */


int any(char *s1, char *s2)
{
    int n = -1;
    int i, j;
    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++)
            if (s1[i] == s2[j]) {
                n = i;
                break;
            }
        if (n != -1) break;
    }
    return n;
}
