int my_strcmp(char *str1, char* str2) 
{
	for(; *str1 == *str2; str1++, str2++)
	{
		if(*str1 == '\0')
			return 0;
	}
	int x = (*str1 - *str2);
	if(x < 0)
		return -1;
	else return 1;
}