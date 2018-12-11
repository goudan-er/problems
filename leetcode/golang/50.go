package leetcode

func myPow(x float64, n int) float64 {
	neg := false
	if n < 0 {
		neg = true
	}
	res := 1.0
	for n > 0 {
		if n&2 == 1 {
			res *= x
		}
		x *= x
		n /= 2
	}
	if neg {
		return 1.0 / res
	}
	return res
}
