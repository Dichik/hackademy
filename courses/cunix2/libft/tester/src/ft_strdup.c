#include <stdlib.h>
#include <string.h>

char *ft_strdup(char * c) {
	char * res = malloc(strlen(c) + 1);
	if(res == NULL) return NULL;
	while( (*res = *c) != '\0') {
		res++;
		c++;
	}  
	res[strlen(c)] = '\0';
	return res;
}
