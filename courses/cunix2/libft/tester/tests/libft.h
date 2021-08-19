#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

//Day 1
void ft_bzero(void * to, int cnt);
int ft_isalpha(char c);
int ft_isdigit(char c);
int ft_isascii(char c);
int ft_toupper(int c);
int ft_tolower(int c);
char* ft_strdup(char * c);
int ft_strncmp(char * str1, char * str2, int num);
char *ft_strchr(const char * str, const char c) ; 
char * ft_strrchr(char * str, char ch);

//Day 2
int ft_abs(int x);
div_t ft_div(int n, int d);
char* ft_strstr(char *str1, char *str2);
char* ft_strnstr(char * str1, char * str2);
void *ft_memset(char *, int z, int);
void *ft_memcpy(void *dest, void *src, int n);
void *ft_memccpy(void *dest, void *src, int ch, int n);
void *ft_memmove(void *dest, void *src, int n);
void *ft_memchr(char *str1, char *str2, int n);
int ft_memcmp(char *str1, char *str2, int n);

//Day 3
void ft_striter(char *s, void (*f)(char));
char * ft_strmap(char const *s, char (*f)(char));
char * ft_strsub(char const *s, unsigned int start, int len);
char * ft_strjoin(char const *s1, char const *s2);
char * ft_strtrim(char const *s);
char ** ft_strsplit(char const *s, char c);
