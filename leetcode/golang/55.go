package leetcode

func canJump(nums []int) bool {
	if len(nums) <= 1 {
		return true
	}
	target := len(nums) - 1
	ret := false
	for cur := len(nums) - 2; cur >= 0; cur-- {
		jump := nums[cur]
		if cur+jump >= target {
			ret = true
			target = cur
		} else {
			ret = false
		}
	}
	return ret
}
