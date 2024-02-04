/* vim:ts=4:sw=4:et:so=10:
 *
 * syscalls.h
 *      A header file "syscalls.h" is included in many examples in chapter 8.
 *      But the listing for this file is not provided. It appears this
 *      syscalls.h header file is intended to provide the 
 *      declarations for the following system calls (functions) 
 *      The text says this header is "not standard".
 */

#ifndef SYSCALLS_H
#define SYSCALLS_H 

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <error.h>

/* Including this header will provide the following functions */
// read()
// write()
// open()
// close()
// lseek()
// error()
// creat() 
// unlink()

/* These are also defined in chapter 8 version of stdio.h */
#ifndef BUFSIZ
#define BUFSIZ 8192
#define NULL 0
#define EOF (-1)
#define OPEN_MAX 20
#endif

#endif // SYSCALLS_H
