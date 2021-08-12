#include <stdio.h>
#include <stdlib.h>

void *ft_memchr(void * str, int c, int n) {
	char * s = (char *)str;
	for(int i = 0; i < n; ++ i) {
		if(*(s + i) == c)
			return s + i;
	}
	return (NULL);
}
