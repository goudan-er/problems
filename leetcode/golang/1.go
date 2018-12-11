package leetcode

func twoSum(nums []int, target int) []int {
	helper := make(map[int]int)

	for i, num := range nums {
		if j, find := helper[target-num]; find {
			return []int{i, j}
		}
		helper[num] = i
	}

	return []int{}
}
