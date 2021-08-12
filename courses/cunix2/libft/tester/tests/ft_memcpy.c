void *ft_memcpy(void *dst, void *src, int n)
{
	for(int i = 0; i < n; ++ i) {
		((char *) dst)[i] = ((char *)src)[i];
	}

	return dst;
}
