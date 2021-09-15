package letter

func Frequency(text string) map[rune]int {
	res := map[rune]int{}

	for _, v := range text {
		res[v]++
	}

	return res
}


func ConcurrentFrequency(text []string) map[rune]int {
	res := map[rune]int{}

	ch := make(chan map[rune]int)
	for _, v := range text {
		go calc(v, ch)
	}

	for range text {
		for k, v := range <- ch {
			res[k] += v
		}
	}

	return res
}

func calc(text string, ch chan map[rune]int) {
	ch <- Frequency(text)
}

