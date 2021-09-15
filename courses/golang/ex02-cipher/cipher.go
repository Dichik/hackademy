package cipher

type Shift struct {
	num int
}

type Cipher interface {
	Encode(string) string
	Decode(string) string
}

func NewCaesar() Cipher {
	return NewShift(3)
}

func NewShift(x int) Cipher {
	if (x >= 1 && x <= 25) || (x <= -1 && x >= -25) {
		var cipher Cipher = &Shift{x}
		return cipher
	} else {
		return nil
	}
}


func isAlpha(x rune) int {
	if x >= 'a' && x <= 'z' {
		return 1
	}
	if x >= 'A' && x <= 'Z' {
		return 2
	}
	return 0
}

func toLower(x rune) rune {
	return x - 'A' + 'a'
}


func getPrev(ch rune, x int) string {
	res := int(ch) - x
	if res < 'a' {
		res = res + 26
	} else if res > 'z' {
		res = res - 26
	}
	return string(rune(res))
}

func getNext(ch rune, x int) string {
	res := int(ch) + x
	if res > int('z') {
		res = res - 26
	} else if res < int('a') {
		res = res + 26
	}
	return string(rune(res))
}


func (cipher Shift) Encode(input string) string {
	x := cipher.num
	result := ""
	for _, v := range input {
		valueOfAlpha := isAlpha(v)
		if valueOfAlpha > 0 {
			if valueOfAlpha == 2 {
				result += getNext(toLower(v), x)
			} else {
				result += getNext(v, x)
			}
		}
	}
	return result
}

func (cipher Shift) Decode(input string) string {
	x := cipher.num
	result := ""
	for _, v := range input {
		result += getPrev(v, x)
	}

	return result
}
