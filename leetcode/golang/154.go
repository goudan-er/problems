package leetcode

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func findMin(nums []int) int {
	l, r := 0, len(nums)-1
	for r-l > 1 {
		mid := (r-l)/2 + l
		if nums[l] == nums[mid] {
			l++
			continue
		}
		// fmt.Println(l, r, mid, nums[l], nums[r], nums[mid])
		if nums[l] <= nums[mid] && nums[mid] <= nums[r] {
			r = mid
		} else if nums[l] <= nums[mid] && nums[mid] > nums[r] {
			l = mid
		} else {
			r = mid
		}
	}
	return min(nums[l], nums[r])
}
