package leetcode

import (
	"sort"
)

func find3Sum(nums []int, target int) [][]int {
	result := [][]int{}
	// sort.Ints(nums)
	for i, cur := range nums {
		if i > 0 && nums[i-1] == nums[i] {
			continue
		}
		l, r := i+1, len(nums)-1
		for l < r {
			sum := cur + nums[l] + nums[r]
			if sum > target {
				r--
			} else if sum < target {
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

func fourSum(nums []int, target int) [][]int {
	result := [][]int{}
	sort.Ints(nums)
	for i := range nums {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		threeSumOfTargetSets := find3Sum(nums[i+1:], target-nums[i])
		if len(threeSumOfTargetSets) > 0 {
			for _, ele := range threeSumOfTargetSets {
				ele = append(ele, nums[0])
				result = append(result, ele)
			}
		}
	}
	return result
}
