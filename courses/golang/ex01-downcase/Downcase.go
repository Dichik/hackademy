package downcase

func isUpper(x string) bool {
	return x[0] >= 'A' && x[0] <= 'Z'
}

func Downcase(str string) (string, error) {
	ans := ""
	for i := 0; i < len(str); i++ {
		if isUpper(string(str[i])) {
			ans += string(str[i] - 'A' + 'a')
		} else {
			ans += string(str[i])
		}
	}
	return ans, nil
}
