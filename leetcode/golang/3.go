package leetcode

func lengthOfLongestSubstring(s string) int {
	l := len(s)
	if l == 0 || l == 1 {
		return l
	}

	prePos := make([]int, l)
	flag := make([]int, 256)
	for i := range flag {
		flag[i] = -1
	}

	for i, c := range s {
		prePos[i] = flag[c]
		flag[c] = i
	}

	ans := 0
	start := 0
	for i, prePosSi := range prePos {
		if prePosSi >= start {
			ans = max(ans, i-prePosSi)
			start = prePosSi + 1
		} else {
			ans = max(ans, i-start+1)
		}
	}

	return ans
}
