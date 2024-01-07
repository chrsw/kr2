/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * hash.c
 *      Form hash value for string.
 *
 * Description:
 *      From Section 6.6 Table Lookup.
 *
 * Build:
 *      Build instructions in main() drivers.
 *
 */

#include "hash.h"


/* hash:  form hash value for string s */
unsigned int hash(char *s)
{
    unsigned int hashval;
    
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}
