/* lower: convert c to lower case; ASCII only */
int lower(int c) {

	if (c >= 'A' && c <= 'Z')
		return c + 'z' - 'A';
	else
		return c;
}
