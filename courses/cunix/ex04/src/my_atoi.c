int my_atoi(const char *s)
{
	int ans = 0;
	int sign = 1;
	if(s[0] == '-') sign = -1;

	while(*s != '\0')
	{
		if(*s - '0' <= 9 && *s - '0' >= 0)
			ans = ans * 10 + (*s - '0');
		s++;
	}
	return ans * sign;
}
