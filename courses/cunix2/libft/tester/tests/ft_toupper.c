char ft_toupper(char c) {
	if(c - 'a' >= 0 && c - 'a' <= 25) {
		char x = (char) (int)(c - 'a' + 'A');
		return x;
	}
	return '\0';
}
