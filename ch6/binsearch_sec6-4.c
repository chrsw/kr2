/* vim:ts=4:sw=4:et:
 *
 * binsearch.c
 *      Search for word in array using binary search algorithm.
 *      Uses an order input search space. If the search key is lower
 *      than the current search mid point then everything in the
 *      search space that's high is ignored. Opposite for search
 *      key being higher than current mid point.
 *      After each search iteration a new mid point is chosen.
 *
 * Description:
 *      Version from Section 6.4. Pointers to Structures.
 *      
 * Build:
 *      See other main() files for build instructions.
 *
 */

#include <string.h>
#include "ckeywords.h"

/* binsearch: 	find word in tab[0]...tab[n-1] */
struct key *binsearch(char *word, struct key tab[], int n) {

	int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while (low <= high) {
        mid = low + (high-low) / 2;
        if ((cond = strcmp(word, mid->word)) < 0)
            high = mid;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    
	return NULL;
}

/* test break */
/* test continue */
