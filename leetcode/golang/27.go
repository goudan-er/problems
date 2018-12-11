package leetcode

func removeElement(nums []int, val int) int {
	cur := -1
	for i := range nums {
		if nums[i] != val {
			cur++
			nums[cur] = nums[i]
		}
	}
	return cur + 1
}
