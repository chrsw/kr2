/* vim:ts=4:sw=4:et:so=10:
 *
 * dcl.h
 * 	Parse C declarations. 
 *
 */

#ifndef DCL_H
#define DCL_H

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);

extern int tokentype;
extern char token[MAXTOKEN];
extern char name[MAXTOKEN];
extern char datatype[MAXTOKEN];
extern char out [1000];




#endif /* DCL_H */
