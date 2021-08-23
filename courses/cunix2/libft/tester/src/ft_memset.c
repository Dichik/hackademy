void *ft_memset(void *dst, char z, int n) {
	if(dst) {
		char * tmp = (char *) dst;
		while(n--) {
			*tmp++ = z;
		}
	}
	return dst;
}
