/*
 * talloc.c
 *      Allocate a tnode for a tree.
 *
 * Notes:
 *      Helpful information for anyone to have who is maintaining this code.
 *
 */

#include <stdlib.h>
#include "tnode.h"
#include "talloc.h"

/* talloc:  allocate space for one node from the environment */

struct tnode *talloc(void) 
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
