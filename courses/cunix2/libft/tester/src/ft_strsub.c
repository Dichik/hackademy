#include <string.h>
#include <stdlib.h>

char * ft_strsub(char const *s, unsigned int start, int len) {
    int sz = strlen(s);
    if(start + len >= sz)
        return NULL;
    char * res ;
    res = (char *) malloc(len * sizeof(char));

    if(res == NULL)
        return NULL;

    int j = 0;
    int i = 0;
    while(sz--) {
        if(i >= start && i < start + len) {
            *(res + j++) = *(s + i);
        }
        i ++;
    }

    return res;
}
