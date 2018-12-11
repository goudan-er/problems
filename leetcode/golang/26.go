package leetcode

func removeDuplicates(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	cur := 0
	for i := range nums {
		if i == 0 || nums[i] == nums[i-1] {
			continue
		}
		cur++
		nums[cur] = nums[i]
	}
	return cur + 1
}
