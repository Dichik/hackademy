#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int compare(const char *str1, const char *str2) {
     while(*str1 && *str2) {
          if(*str1 != *str2)
               return 0;
          str1++;
          str2++;
     }

     return (*str2 == '\0');
}

void *ft_strstr(char * str1, char * str2) {
     if( strlen(str2) > strlen(str1) ) return NULL;

     if(str2 == "") return str1;

	while(*str1 != '\0') {
          if( (*str1 == *str2) && compare(str1, str2) )
               return str1;
          str1++;
	}

	return NULL;
}
