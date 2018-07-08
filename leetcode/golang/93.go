package leetcode

import (
	"strconv"
	"strings"
)

func restoreHelper(s string, idx int, flag int, cur []string, result *[]string) {
	l := len(s)
	if flag == 4 {
		num, err := strconv.Atoi(s[idx:])
		if err == nil && num >= 0 && num <= 255 && (idx == l-1 || s[idx] != '0') {
			cur = append(cur, s[idx:])
			*result = append(*result, strings.Join(cur, "."))
		}
	} else {
		for i := 1; i <= 3 && idx+i <= l; i++ {
			num, err := strconv.Atoi(s[idx : idx+i])
			if err == nil && num >= 0 && num <= 255 && (i == 1 || s[idx] != '0') {
				cur := append(cur, s[idx:idx+i])
				restoreHelper(s, idx+i, flag+1, cur, result)
			}
		}
	}
}

func restoreIpAddresses(s string) []string {
	result := []string{}
	restoreHelper(s, 0, 1, []string{}, &result)
	return result
}
