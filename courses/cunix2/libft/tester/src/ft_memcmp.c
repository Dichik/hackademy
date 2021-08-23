int ft_memcmp(char * str1, char * str2, int n) {
	while(n--) { 
		if(*str1 != *str2)
			return *str2 - *str1;
		str2++;
		str1++;
	}
	return 0;
}
