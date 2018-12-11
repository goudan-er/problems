package leetcode

import (
	"math"
	"sort"
)

func threeSumClosest(nums []int, target int) int {
	sort.Ints(nums)
	abs, result := math.MaxInt32, 0
	for i, cur := range nums {
		l, r := i+1, len(nums)-1
		for l < r {
			sum := cur + nums[l] + nums[r]
			if sum > target {
				r--
			} else {
				l++
			}
			if abs < int(math.Abs(float64(sum-target))) {
				result = sum
				abs = int(math.Abs(float64(sum - target)))
			}
		}
	}
	return result
}
