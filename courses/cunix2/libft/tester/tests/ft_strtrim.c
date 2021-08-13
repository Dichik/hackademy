#include <string.h>
#include <stdlib.h>

char * ft_strtrim (char const *s) {
     int n = strlen(s);

     int l = 0;
     int r = 0;

     for(int i = 0; i < n; ++ i) {
            switch( *(s + i) ) {
            case ' ':
                l++;
                break;
            case '\n':
                l++;
                break;
            case '\t':
                l++;
                break;
            default:
                i = n;
                break;
            }
     }

     for(int i = n - 1; i > l; -- i) {
            switch( *(s + i) ) {
            case ' ':
                r++;
                break;
            case '\n':
                r++;
                break;
            case '\t':
                r++;
                break;
            default:
                i = l;
                break;
            }
     }
    char * res;
    res = (char *) malloc(sizeof(char) * (n - l - r + 1));

    if(res == NULL) {
        return NULL;
    }


    for(int i = l, j = 0; i < n - r; ++ i) {
        *(res + j++) = *(s + i);
    }
    res[n - r - l] = '\0';

    return res;
}
