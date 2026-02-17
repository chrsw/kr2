// table.h

struct nlist {                  /* table entry */
    struct nlist *next;         /* next entry in chain */
    char *name;                 /* defined name */
    char *defn;                 /* replacement text */
};

struct nlist *install(char *name, char *defn);
struct nlist *lookup(char *s);
