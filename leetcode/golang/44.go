package leetcode

import (
	"strings"
)

func isMatch(ss string, pp string) bool {
	vis := make([][]bool, len(ss))
	for i := range vis {
		vis[i] = make([]bool, len(pp))
	}
	var isMatchHelper func(s string, p string) bool
	isMatchHelper = func(s string, p string) bool {
		if len(s) == 0 && len(p) == 0 {
			return true
		} else if len(s) != 0 && len(p) == 0 {
			return false
		} else if len(s) == 0 && len(p) != 0 {
			if strings.Count(p, "*") == len(p) {
				return true
			}
			return false
		}

		if vis[len(s)-1][len(p)-1] == true {
			return false
		}

		vis[len(s)-1][len(p)-1] = true

		// both s and p are not empty
		if p[0] == '*' {
			return isMatchHelper(s, p[1:]) || isMatchHelper(s[1:], p)
		}
		if p[0] == '?' || s[0] == p[0] {
			return isMatchHelper(s[1:], p[1:])
		}

		return false
	}

	return isMatchHelper(ss, pp)
}
