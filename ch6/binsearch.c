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
 *      For use with chpater 6, exercise 1.
 *
 */

#include <string.h>
#include "ckeywords.h"

/* binsearch: 	find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct key tab[], int n) {

	int cond;
	int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high)/2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    
	return -1;
}

/* test break */
/* test continue */
