package leetcode

func reverse(nums []int) []int {
	for i, j := 0, len(nums)-1; i < j; i, j = i+1, j-1 {
		nums[i], nums[j] = nums[j], nums[i]
	}
	return nums
}

func rotate(nums []int, k int) {
	idx := len(nums) - k%len(nums)
	reverse(nums[0:idx])
	reverse(nums[idx:])
	reverse(nums)
}
