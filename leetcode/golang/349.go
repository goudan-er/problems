package leetcode

func intersection(nums1 []int, nums2 []int) []int {
	mark := make(map[int]bool)
	for _, num := range nums1 {
		if _, ok := mark[num]; !ok {
			mark[num] = false
		}
	}
	res := []int{}
	for _, num := range nums2 {
		if inRes, ok := mark[num]; ok && !inRes {
			res = append(res, num)
			mark[num] = true
		}
	}
	return res
}
