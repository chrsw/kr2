/* vim:ts=4:sw=4:et:so=10:
 *
 * dcl.h
 * 	Parse C declarations. 
 *
 */

#ifndef DCL_EX5_20_H
#define DCL_EX5_20_H

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS, ARG };

void dcl(void);
void dirdcl(void);

extern int tokentype;
extern char token[MAXTOKEN];
extern char name[MAXTOKEN];
extern char datatype[MAXTOKEN];
extern char out [1000];
extern char arg[MAXTOKEN];




#endif /* DCL_EX5_20_H */
