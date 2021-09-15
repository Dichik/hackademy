package cipher

type Vig struct {
	str string
}

func NewVigenere(str string) Cipher {
	if !hasBlockedCharacters(str) {
		var rs Cipher = &Vig{str}
		return rs
	}
	return nil
}

func (cipher Vig) Encode(input string) string {
	key := cipher.str
	j := 0
	result := ""
	for _, v := range input {
		valueOfAlpha := isAlpha(v)
		if valueOfAlpha > 0 {
			if j >= len(key) {
				j = 0
			}
			x := int(key[j] - 'a')
			j++
			if valueOfAlpha == 2 {
				result += getNext(toLower(v), x)
			} else {
				result += getNext(v, x)
			}
		}
	}
	return result
}

func (cipher Vig) Decode(input string) string {
	j := 0
	res := ""
	key := cipher.str
	for i := 0; i < len(input); i++ {
		if j >= len(key) {
			j = 0
		}
		delta := key[j] - 'a'
		j++
		nwStr := input[i] - delta
		if nwStr < 'a' {
			nwStr += 26
		}
		res += string(nwStr)
	}
	return res
}

func hasBlockedCharacters(str string) bool {
	wasNotA := false
	for _, v := range str {
		if v < 'a' || v > 'z' {
			return true
		}
		if v != 'a' {
			wasNotA = true
		}
	}
	return !wasNotA
}