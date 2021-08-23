int ft_isalpha(char c) {
	if(c - 'a' >= 0 && c - 'a' <= 25) {
		return 1;
	}
	if(c - 'A' >= 0 && c - 'A' <= 25)
		return 1;
	return 0;
}
