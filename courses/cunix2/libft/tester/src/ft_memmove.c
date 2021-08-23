#include <stdlib.h>

void *ft_memmove(void *dst, void *src, int n) {
	char * str1 = (char *) dst;
	char * str2 = (char *) src;

	char * tmp = (char *) malloc(sizeof(char) * n);
	if(tmp == NULL) return NULL;
	
	for(int i = 0; i < n; ++ i) {
		*(tmp + i) = *(str2 + i);
	}

	for(int i = 0; i < n; ++ i)
		*(str1 + i) = *(tmp + i);
	free(tmp);
	return dst;
}
