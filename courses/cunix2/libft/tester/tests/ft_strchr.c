char *ft_strchr(char * str, char c) {
	while( *str != c && *str != '\0') {
		str++;
	}
	if(*str == c)
		return str;
	return '\0'; 
}
