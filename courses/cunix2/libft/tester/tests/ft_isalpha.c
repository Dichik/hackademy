int ft_isalpha(char c) {
	if(c - 'a' >= 0 && c - 'a' < 26) {
		return 1;
	}
	return 0;
}
