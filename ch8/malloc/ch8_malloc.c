/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * ch8_malloc.c
 *      malloc() and related code from K&R2 Chapter 8.
 *
 * Description:
 *      Template for code and solutions to exercises in The C Programming
 *      Language 2nd Ed. A longer description of the program goes here.
 *      This file defines the functions malloc(), free() and morecore() as
 *      written in the text, except modified to build and link into a real
 *      application on a modern Linux system (2023-24 time frame).
 *
 * Input:
 *      Describe the expected input.
 *
 * Output:
 *      What output does this program generate? stdout, stderr, files, etc.
 *
 * Design:
 *      Details about the design, theory and options taken for the
 *      implemented solution.
 * 
 * Implementation:
 *      Details on how the code you're reading implements the design.
 *
 * Build:
 *      $ gcc -Wall -Wextra -Wpedantic -c ch8_malloc.c
 *
 * Run:
 *      An example of how this program should be run.
 *
 */

#include <unistd.h>
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

static Header *morecore(unsigned);


static Header base;                     /* empty list to get started */
static Header *freep = NULL;            /* start of free list */

/* malloc:  general-purpose storage allocator */
void *ch8_malloc(unsigned nbytes)
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