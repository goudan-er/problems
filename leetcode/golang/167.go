package leetcode

func twoSum(numbers []int, target int) []int {
	firstMap := make(map[int]int)
	for i, num := range numbers {
		j, ok := firstMap[target-num]
		if ok {
			return []int{j + 1, i + 1}
		}
		firstMap[num] = i
	}

	// return error
	return []int{-1, -1}
}
