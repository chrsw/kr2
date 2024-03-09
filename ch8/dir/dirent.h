/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * dirent.h
 *      System-independent access to the name and inode number in a
 *      directory entry.
 *
 */

#ifndef DIRENT_H
#define DIRENT_H

#ifndef NAME_MAX
#define NAME_MAX    14  /* longest filename component: system-dependent */
#endif

typedef struct {            /* portable directory entry */
    long ino;               /* inode number */
    char name[NAME_MAX+1];  /* name + '\0' terminator */
} ch8_Dirent;

typedef struct {            /* minimal DIR: no buffering, etc. */
    int fd;                 /* file descriptor for directory */
    ch8_Dirent d;               /* the directory entry */
} ch8_DIR;

ch8_DIR *ch8_opendir(char *dirname);
ch8_Dirent *ch8_readdir(ch8_DIR *dfd);
void ch8_closedir(ch8_DIR *dfd);

#endif /* DIRENT_H */
