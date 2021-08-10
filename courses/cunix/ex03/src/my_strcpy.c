char *my_strcpy(char *dest, const char *src)
{
	int i = 0;
	while((dest[i] = src[i]) != '\0')
	{
		i++;
	}
	return dest;
}
