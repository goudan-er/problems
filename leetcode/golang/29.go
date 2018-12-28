package leetcode

import "math"

func absi64(num int64) int64 {
	if num < 0 {
		return -num
	}
	return num
}

func divide(dividend int, divisor int) int {
	positive := 1
	if dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0 {
		positive = -1
	}
	dividend64, divisor64, res := absi64(int64(dividend)), absi64(int64(divisor)), 0
	for dividend64 >= divisor64 {
		quickDivisor64, shift := divisor64, 1
		for dividend64 >= (quickDivisor64 << 1) {
			quickDivisor64 <<= 1
			shift <<= 1
		}
		dividend64 -= quickDivisor64
		res += shift
	}
	res = positive * res
	if res > math.MaxInt32 {
		return math.MaxInt32
	} else if res < math.MinInt32 {
		return math.MinInt32
	}
	return res
}
