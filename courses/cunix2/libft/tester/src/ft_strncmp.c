#include <stdlib.h>
#include <string.h>

int _max(int x, int y) {
     if(x > y) return x;
     return y;
}

int  _min(int x, int y) {
     if(x < y) return x;
     return y;
}

int ft_strncmp(char * str1, char * str2, int num) {
     if(num < 0) return -1;

	int mx = _max(strlen(str1), strlen(str2));
	for(int i = 0; i < _min(num, mx); ++ i) {
          if( *(str1 + i) != *(str2 + i) ) {
              return *(str1 + i) - *(str2 + i);
          }
	}
	return 0;
}
