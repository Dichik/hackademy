#include <stdio.h>

#ifndef EOF
# define EOF (-1)
#endif

int my_puts(const char *s) {
	int i = 0;
	while(s[i]) {
		if(putchar(s[i]) == EOF) {
			return EOF;
		}
		i++;
	}
	if(putchar('\n')) 
		return EOF;
	return 1;
}
