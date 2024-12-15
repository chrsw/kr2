/*
 * ex2-10.c
 *      lower() using conditionals. 
 *
 * Description:
 *      Rewrite the function lower() (end of file), which converts
 *      upper case letters to lower case, with a conditional expression
 *		instead of if-else.
 *
 * Input:
 *      Lower case value.
 *
 * Returns:
 *      After running, check the return value of the program in the shell.
 *      Example:
 *              $ echo $?
 *
 */

int lower(int c);
int lower_cond(int c);

int main(int argc, char *argv[]) {

    int c = 'N';

	return lower_cond(c);
}

int lower_cond(int c) {

    return ( (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : (c));
}


/* lower: convert c to lower case; ASCII only */
/* original version from text */
int lower(int c) {

	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}
  
