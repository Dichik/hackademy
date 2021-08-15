#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

char *rev (char *str) {
     int i;
     int len = 0;
     char c;
     if (!str)
          return NULL;
     while(str[len] != '\0') {
          len++;
     }
     for(i = 0; i < (len/2); i++) {
          c = str[i];
          str [i] = str[len - i - 1];
          str[len - i - 1] = c;
     }
     return str;
}

char * my_itoa(int i, char *strout) {
     char *str = strout;
     int digit, sign = 0;
     if (i < 0) {
          sign = 1;
          i *= -1;
     }
     while(i) {
          digit = i % 10;
          *str = (digit > 9) ? ('A' + digit - 10) : '0' + digit;
          i = i / 10;
          str ++;
     }
     if(sign) {
          *str++ = '-';
     }
     *str = '\0';
     rev(strout);
     return strout;
}

int ft_printf (char * str, ...) {
     va_list vl;
     int i = 0, j = 0;
     char buff[100] = {0}, tmp[100];
     char * str_arg;

     va_start(vl, str);

     while(str && str[i]) {
          if(str[i] == '%') {
               ++ i;
               switch(str[i]) {
               case 'd':
                    my_itoa(va_arg(vl, int), tmp);
                    strcpy(&buff[j], tmp);
                    j += strlen(tmp);
                    break;
               case 's':
                    str_arg = va_arg(vl, char *);
                    strcpy(&buff[j], str_arg);
                    j += strlen(str_arg);
                    break;
               case 'i':
                    my_itoa(va_arg(vl, int), tmp);
                    strcpy(&buff[j], tmp);
                    j += strlen(tmp);
                    break;
               case 'c':
                    buff[j++] = (char) va_arg(vl, int);
                    break;
               default:
                    break;
               }
          } else {
               buff[j++] = str[i];
          }
          ++ i;
     }
     fwrite(&buff, j, 1, stdout);
     va_end(vl);
     return j;
}
