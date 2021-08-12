#include <string.h>

void *ft_strstr(char * str1, char * str2) {
	int n = strlen(str1);
	int m = strlen(str2);
	for(int i = 0; i < n - m; ++ i) {
		int cnt = 0;
		for(int j = 0; j < m; ++ j) {
			if(*(str1 + i + j) == *(str2 + j))
				cnt++;
			else break;
		}
		if(cnt == m) {
			while(i--) str1++;
			return str1;
		}
	}

	return NULL;
}
