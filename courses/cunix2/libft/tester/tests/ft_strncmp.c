int ft_strncmp(char * str1, char * str2, int num) {
	int i = 0;
	while(num > 0 && *str1 == *str2) {
		num--;
		str1++;
		str2++;
	}
	if(str1 == '\0' && num <= 0)
		return 0;
	return *str1 - *str2;
}
