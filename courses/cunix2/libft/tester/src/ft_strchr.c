#include <string.h>
#include <stdlib.h>

char *ft_strchr(char * str, int c) {
     if(c >= 127) return str;

	while( *str != c && *str != '\0') {
		str++;
	}
	if(*str == c)
		return str;
	return NULL;
}
