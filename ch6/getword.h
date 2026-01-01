/* getword:  get next word or character from input K&R2, page 136  */
int getword(char *word, int lim);

/* bgetword:  get next word or character from input. Handles underscores. */
int bgetword(char *word, int lim);

/* getwordb:  get next word or character from input */
int getwordb(char *word, int lim);

/* dgetword:  get next word or character from input. Handles hash marks. */
int dgetword(char *word, int lim);