package leetcode

func lowerBound(nums []int, target int) int {
	res, l, r := -1, 0, len(nums)-1
	for l <= r {
		mid := (r-l)/2 + l
		if nums[mid] == target {
			res = mid
			r = mid - 1
		} else if nums[mid] > target {
			r = mid - 1
		} else {
			l = mid + 1
		}
	}
	return res
}

func upperBound(nums []int, target int) int {
	res, l, r := -1, 0, len(nums)-1
	for l <= r {
		mid := (r-l)/2 + l
		if nums[mid] == target {
			res = mid
			l = mid + 1
		} else if nums[mid] > target {
			r = mid - 1
		} else {
			l = mid + 1
		}
	}
	return res
}

func searchRange(nums []int, target int) []int {
	return []int{lowerBound(nums, target), upperBound(nums, target)}
}
