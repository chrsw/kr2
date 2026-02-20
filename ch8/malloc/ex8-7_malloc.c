/*
 * ex8-7_malloc.c
 *
 * Description:
 *      Excerpt from K&R2, Chapter 8, Section 7.
 *      Minor name changes to avoid conflicts with the
 *      system malloc() and free(). Additional changes needed
 *      so the code builds without warnings or problems on
 *      modern systems.
 *      ch8_malloc(), ch8_free() and morecore() implement a
 *      simple storage allocator using a linked list to keep
 *      track of memory blocks.
 *
 * Build example(s):
 *      $ gcc -Wall -Wextra -Wpedantic -c ch8_malloc.c
 *
 */

#include <unistd.h>
#include <limits.h>
#include "ch8_malloc.h"


typedef long Align;                     /* for alignment to long boundary */

union header {                          /* block header */
    struct {
        union header *ptr;              /* next block if on free list */
        unsigned size;                  /* size of this block */
    } s;
    Align x;                            /* force alignment of blocks */
};

typedef union header Header;


static Header base;                     /* empty list to get started */
static Header *freep = NULL;            /* start of free list */


/* ch8_malloc:  general-purpose storage allocator */
void *ch8_malloc(unsigned nbytes)
{
    Header *p, *prevp;
    Header *morecore(unsigned);
    unsigned nunits;

    if (nbytes < 1 || nbytes > INT_MAX/2) return NULL;

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
            return (void *)(p+1);
        }
        if (p == freep)                     /* wrapped around free list */
            if ((p = morecore(nunits)) == NULL)
                return NULL;                /* none left */
    }

}


#define NALLOC 1024                         /* minimum #units to request */

/* morecore:  ask system for more memory */
Header *morecore(unsigned nu)
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


/* ch8_free:  put block ap in free list */
void ch8_free(void *ap)
{
    Header *bp, *p;

    bp = (Header *)ap;
    if (bp->s.size < 1 )
        return;
    else
        bp = (Header *)ap - 1;              /* point to block header */
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
