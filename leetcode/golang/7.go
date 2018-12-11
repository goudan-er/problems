package leetcode

import (
	"math"
)

func reverse(x int) int {
	neg := false
	if x < 0 {
		x = -x
		neg = true
	}

	y := 0
	for x != 0 {
		y = y*10 + x%10
		x = x / 10
	}

	if neg {
		y = -y
	}

	if y > math.MaxInt32 || y < math.MinInt32 {
		y = 0
	}

	return y
}
