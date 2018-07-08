package leetcode

func findPeakElement(nums []int) int {
	n := len(nums)
	if n == 1 {
		return 0
	}
	if n == 2 {
		if nums[0] > nums[1] {
			return 0
		} else {
			return 1
		}
	}

	// binary search
	mid := n / 2
	if nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1] {
		return mid
	} else if nums[mid-1] > nums[mid] && nums[mid-1] > nums[mid+1] {
		return findPeakElement(nums[0:mid])
	} else { // nums[mid+1] > nums[mid-1] && nums[mid+1] > nums[mid]
		return mid + 1 + findPeakElement(nums[mid+1:])
	}
}
