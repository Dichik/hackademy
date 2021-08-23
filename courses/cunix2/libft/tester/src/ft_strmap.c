#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

char * ft_strmap(char const *s, char (*f)(char)) {
        char * res ;
        int len = (int)strlen(s);

        int i = 0;
        int k = len;
        res = (char *)malloc( (len + 1) * sizeof(char));
        for(int i = 0; i < len; ++ i ) {
                char x = (*f)(*(s + i));
                *(res + i) = x;
        }
        res[len] = '\0';
        return res;
}

