typedef struct {
	int q;
	int rem;
} div_t;

div_t ft_div(int num, int den) {
	div_t res;
	res.q = num / den;
	res.rem = num % den;
	return res;
}
