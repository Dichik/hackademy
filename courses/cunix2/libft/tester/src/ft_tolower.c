int ft_tolower(int c) {
	if(c - 'A' >= 0 && c - 'A' <= 25) {
		return (char) (int)(c - 'A' + 'a');
	}
	return c;
}
