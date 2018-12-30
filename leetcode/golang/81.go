package leetcode

func search(nums []int, target int) bool {
	l, r := 0, len(nums)-1
	for l <= r {
		mid := (r-l)/2 + l
		if target == nums[mid] {
			return true
		}

		if nums[mid] == nums[l] {
			l++
		} else if nums[mid] > nums[l] {
			if target <= nums[mid] && target >= nums[l] {
				r = mid - 1
			} else {
				l = mid + 1
			}
		} else {
			if target >= nums[mid] && target <= nums[r] {
				l = mid + 1
			} else {
				r = mid - 1
			}
		}
	}
	return false
}
