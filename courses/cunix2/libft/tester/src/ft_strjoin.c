#include <string.h>
#include <stdlib.h>

char * ft_strjoin(char const *s1, char const *s2) {
    int sz1 = strlen(s1);
    int sz2 = strlen(s2);

    int len = sz1 + sz2 + 1;
    int i = 0;
    int j = 0;

    char * res ;
    res = (char *) malloc(sizeof(char) * len);

    if(res == NULL)
        return NULL;

    while(sz1--) {
        *(res + j++) = *(s1 + i++);
    }
    i = 0;
    while(sz2 --) {
        *(res + j++) = *(s2 + i++);
    }
    res[len] = '\0';

    return res;
}
