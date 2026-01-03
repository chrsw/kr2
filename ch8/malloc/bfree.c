/*
 * bfree.c
 *      Free an arbitrary block of memory. Part of solution to 
 *      Exercise 8-8.
 *
 * Description:
 *      Write a routine bfree(pn,) that will free an arbitrary block p of n
 *      characters into the free list maintained by malloc() and free(). By
 *      using bfree(), a user can add a static or external array to the free
 *      list at any time.
 *      
 * Build:
 *      $ gcc -o bfree bfree.c ch8_malloc.c
 *
 */


void bfree(void *p, unsigned int n) {

    (void)p;
    (void)n;
}


int main(int argc, char *argv[]) {

    return 0;
}
