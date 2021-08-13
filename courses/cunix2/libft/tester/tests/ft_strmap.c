#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char * ft_strmap(char const *s, char (*f)(char)) {
        char * res ;
        int len = (int)strlen(s) + 1;

        int i = 0;
        int k = len - 1;
        res = (char *)malloc(len * sizeof(char));
        while(k--) {
                char x = (*f)(*(s + i));
                *(res + i++) = 'x';
        }
        res[len] = '\0';
        return res;
}
