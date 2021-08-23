#include <stdlib.h>
#include <string.h>

int q = 0;
char ** ft_strsplit(char const *s, char c) {
    int n = strlen(s);
    char ** res = malloc(100 * sizeof(char *));

    char * str;
    int len = 0;
    for(int i = 0; i < n; ++ i) {
        if( *(s + i) == c ) {
            if(len == 0) continue;
            else {
                res[q] = malloc(sizeof(char) * len);
                strcpy(res[q], str);
                q++; len = 0; free(str);
            }
        } else {
            if(len == 0) {
                str = malloc(sizeof(char) * 100);
            }
            *(str + len++) = *(s + i);
        }
    }

    return res;
}
