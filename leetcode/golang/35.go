package leetcode

func lowerBound(nums []int, target int) int {
	l, r, res := 0, len(nums)-1, len(nums)-1
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

func searchInsert(nums []int, target int) int {
	return lowerBound(nums, target)
}
