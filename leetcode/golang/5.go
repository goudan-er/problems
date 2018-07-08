package leetcode

func getLongestPalindrome(s string, l int, r int) (string, int) {
	length := len(s)
	for l-1 >= 0 && r+1 < length {
		if s[l-1] != s[r+1] {
			break
		}
		l--
		r++
	}

	return s[l : r+1], r - l + 1
}

func longestPalindrome(s string) string {
	var ans string
	var ansLen int
	for mid := range s {
		l, r := mid, mid
		tmpS, tmpLen := getLongestPalindrome(s, l, r)
		if tmpLen > ansLen {
			ansLen = tmpLen
			ans = tmpS
		}

		l, r = mid, mid+1
		if s[l] == s[r] {
			tmpS, tmpLen = getLongestPalindrome(s, l, r)
			if tmpLen > ansLen {
				ansLen = tmpLen
				ans = tmpS
			}
		}
	}

	return ans
}
