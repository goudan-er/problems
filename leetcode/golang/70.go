package leetcode

func climbStairs(n int) int {
	if n == 0 || n == 1 {
		return 1
	}
	if n == 2 {
		return 2
	}
	pre2, pre1, ret := 1, 2, 0
	for i := 3; i <= n; i++ {
		ret = pre1 + pre2
		pre2 = pre1
		pre1 = ret
	}
	return ret
}
