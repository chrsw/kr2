/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * malloc.h
 *      malloc() header file. Adapted from Section 8.7 - Example:
 *      Storage Alocator.
 *
 */

#ifndef CH8_MALLOC_H
#define CH8_MALLOC_H

void *ch8_malloc(unsigned);
void ch8_free(void *);

#endif /* CH8_MALLOC_H */
