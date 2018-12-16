package leetcode

func lowerBound(nums []int, target int) int {
	l, r, res := 0, len(nums)-1, len(nums)
	for l <= r {
		mid := (r-l)/2 + l
		if target > nums[mid] {
			l = mid + 1
		} else {
			res = mid
			r = mid - 1
		}
	}
	return res
}

func lengthOfLIS(nums []int) int {
	res := []int{}
	for _, num := range nums {
		bound := lowerBound(res, num)
		if bound == len(res) {
			res = append(res, num)
		} else {
			res[bound] = num
		}
	}
	return len(res)
}
