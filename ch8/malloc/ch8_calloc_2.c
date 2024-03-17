/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * ch8_calloc.c
 *      calloc() and related code from K&R2 Chapter 8. Part of solution to
 *      Exercise 8-6.
 *
 * Description:
 *      The calloc() function takes arguments for an object count and object
 *      size, and allocates enough space to store the count of size objects.
 *      The space allocated is cleared to 0 value.
 *
 *      Similar to malloc() but with additional functionality.
 * 
 * Implementation:
 *      This version of calloc() is a re-write of malloc(), there is an
 *      additional argument for the size of each object. There is an additional
 *      statement for the clearing of all allocated data. No definition of
 *      malloc() in this file.
 *
 * Build:
 *      $ gcc -Wall -Wextra -Wpedantic -c ch8_calloc_2.c
 *
 */

#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include "ch8_calloc.h"

typedef long Align;                     /* for alignment to long boundary */

union header {                          /* block header */
    struct {
        union header *ptr;              /* next block if on free list */
        unsigned size;                  /* size of this block */
    } s;
    Align x;                            /* force alignment of blocks */
};

typedef union header Header;

static Header *morecore(unsigned);


static Header base;                     /* empty list to get started */
static Header *freep = NULL;            /* start of free list */

/* calloc:  general-purpose storage allocator */
void *ch8_calloc(unsigned nbytes, size_t size)
{
    Header *p, *prevp;

    unsigned nunits;

    nunits = (nbytes+sizeof(Header)-1)/sizeof(Header) + 1;
    if ((prevp = freep) == NULL) {          /* no free list yet */
        base.s.ptr = freep = prevp = &base;
        base.s.size = 0;
    }
    for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {
        if (p->s.size >= nunits) {          /* big enough */
            if (p->s.size == nunits)        /* exactly */
                prevp->s.ptr = p->s.ptr;
            else {                          /* allocate tail end */
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }
        freep = prevp;
        memset((char *)(p+1), 0, nbytes*size);
        return (void *)(p+1);
        }
        if (p == freep)                     /* wrapped around free list */
            if ((p = morecore(nunits)) == NULL) 
                return NULL;                /* none left */
    }
}


#define NALLOC 1024


/* morecore:  ask system for more memory */
static Header *morecore(unsigned nu)
{
    char *cp;
    Header *up;

    if (nu < NALLOC)
        nu = NALLOC;
    cp = sbrk((intptr_t)(nu * sizeof(Header)));
    if (cp == (char *) -1)                  /* no space at all */
        return NULL;
    up = (Header *) cp;
    up->s.size = nu;
    ch8_free((void *)(up+1));
    return freep;
}


/* free:  put block ap in free list */
void ch8_free(void *ap)
{
    Header *bp, *p;
    bp = (Header *)ap - 1;
    for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
        if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
            break;       /* freed block at start or end of arena */
    
    if (bp + bp->s.size == p->s.ptr) {      /* join to upper nbr */
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    } else
        bp->s.ptr = p->s.ptr;
    if (p + p->s.size == bp) {              /* join to lower nbr */
        p->s.size += bp->s.size;
        p->s.ptr = bp->s.ptr;
    } else
        p->s.ptr = bp;
    freep = p;
}