package leetcode

import (
	"strconv"
)

// f[i] = f[i-1] + f[i-2]

func numDecodings(s string) int {
	l := len(s)
	f := make([]int, l+1)
	f[0] = 1
	for i := 1; i <= l; i++ {
		n, _ := strconv.Atoi(s[i-1 : i])
		if n > 0 {
			f[i] += f[i-1]
		}
		if i >= 2 {
			m, _ := strconv.Atoi(s[i-2 : i])
			if s[i-2] != '0' && m >= 1 && m <= 26 {
				f[i] += f[i-2]
			}
		}
	}

	return f[l]
}
