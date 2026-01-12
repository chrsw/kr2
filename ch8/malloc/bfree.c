/*
 * bfree.c
 *      Free an arbitrary block of memory. Part of solution to 
 *      Exercise 8-8.
 *
 * Description:
 *      Exercise 8-8. Write a routine bfree(pn,) that will free an arbitrary
 *      block p of n characters into the free list maintained by malloc()
 *      and free(). By using bfree(), a user can add a static or external
 *      array to the free list at any time.
 *
 * Design:
 *      The solution creates a static array, uses bfree() to add it to the
 *      ch8_malloc()/ch8_free() free list. bfree() uses ch8_free() to insert
 *      a pointer to the static data into the free linked list structure.
 *      A call to ch8_malloc() obtains memory from that region. Various
 *      memory addresses are printed showing which pointers are exist in
 *      which memory sectors.     
 *      
 * Build:
 *      $ gcc -o bfree bfree.c
 *
 * Run:
 *      $ ./bfree
 *
 */

#include <unistd.h>
#include <stdio.h>
#include "ch8_malloc.h"

void bfree(char *p, unsigned int n);

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

char gca_bf_data[104108];                 /* for adding to the free list with bfree() */ 

/* ch8_malloc:  general-purpose storage allocator */
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


#define NALLOC 1024                         /* minimum #units to request */

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


/* ch8_free:  put block ap in free list */
void ch8_free(void *ap)
{
    Header *bp, *p;
    int count = 0;

    bp = (Header *)ap - 1;              /* point to block header */
    for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr) {
        if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
            break;       /* freed block at start or end of arena */
    }
    if (bp + bp->s.size == p->s.ptr) {      /* join to upper nbr */
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    } else {
        bp->s.ptr = p->s.ptr;
    }
    if (p + p->s.size == bp) {              /* join to lower nbr */
        p->s.size += bp->s.size;
        p->s.ptr = bp->s.ptr;
    } else {
        p->s.ptr = bp;
    }
    freep = p;
}


/* bfree:  free block of memory into ch8_malloc() and ch8_free() free list */
void bfree(char *p, unsigned int n) {

    Header *bp = NULL;

    // create a header for p.
    bp = (Header *)p;
    bp->s.ptr = NULL;
    bp->s.size = n-sizeof(Header);

    // insert the static memory p into the free list
    ch8_free((void *)(bp+1));
}


/* bfree() test driver */
int main(int argc, char *argv[]) {

    char *heap_data1024 = NULL;
    char *heap_data2048 = NULL;
    char *sp = NULL;
    char *sp0 = NULL;

    heap_data1024 = ch8_malloc(1024);
    heap_data2048 = ch8_malloc(2048);
    
    printf("A memory address in heap_data1024:\t%p\n", heap_data1024+4);
    printf("A memory address in heap_data2048:\t%p\n", heap_data2048+4);
    printf("A memory address in gca_bf_data:\t%p\n", gca_bf_data+4);
    char *heap_data_huge = ch8_malloc(16*16*256);
    bfree(gca_bf_data, 4096);
    sp = ch8_malloc(4000); 

    if (sp == NULL) {
        printf("Memory allocations done, check return code\n");
        return -1;
    }
    else {
        printf("A memory address in sp:\t\t\t%p\n", sp+=4);
        printf("Memory allocations done, check return code\n");
        return 0;
    }
}


