char * ft_strrchr(char * str, char ch) {
	char * rs = '\0';
	while(*str != '\0') {
		if(*str == ch) {
			rs = str;
		}
	}
	return rs;
}
