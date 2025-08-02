#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];    /* storage for alloc */
static char *allocp = allocbuf;     /* next free position */


/* return pointer to n characters */
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {   /* if it fits */
        allocp += n;
        return allocp - n;      /*old p */
    } else {                    /* not enough room */ 
        return 0;
    }
}


/* free storage pointed to by p */
void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
