int ft_toupper(int c) {
	if(c - 'a' >= 0 && c - 'a' <= 25) {
		char x = (char) (int)(c - 'a' + 'A');
		return x;
	}
	return c;
}
