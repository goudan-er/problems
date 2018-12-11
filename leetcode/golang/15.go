package leetcode

import (
	"sort"
)

func threeSum(nums []int) [][]int {
	result := [][]int{}
	sort.Ints(nums)
	for i, cur := range nums {
		if i > 0 && nums[i-1] == nums[i] {
			continue
		}
		l, r := i+1, len(nums)-1
		for l < r {
			sum := cur + nums[l] + nums[r]
			if sum > 0 {
				r--
			} else if sum < 0 {
				l++
			} else {
				result = append(result, append([]int{}, cur, nums[l], nums[r]))
				for l+1 < len(nums) && nums[l] == nums[l+1] {
					l++
				}
				for r-1 >= 0 && nums[r] == nums[r-1] {
					r--
				}
				l++
				r--
			}
		}
	}
	return result
}
