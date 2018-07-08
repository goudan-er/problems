package leetcode

import "strings"

func longestCommonPrefix(strs []string) string {
	n := len(strs)
	if n == 0 {
		return strs[0]
	}

	l := len(strs[0])
	for i := 1; i < n; i++ {
		if len(strs[i]) < l {
			l = len(strs[i])
		}
	}

	for i := l; i > 0; i-- {
		flag := true
		for _, s := range strs {
			if strings.Compare(strs[0][0:i], s[0:i]) != 0 {
				flag = false
				break
			}
		}
		if flag == true {
			return strs[0][0:l]
		}
	}

	return ""
}
