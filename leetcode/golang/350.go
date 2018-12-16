package leetcode

func intersect(nums1 []int, nums2 []int) []int {
	mark := make(map[int]int)
	for _, num := range nums1 {
		if _, ok := mark[num]; !ok {
			mark[num] = 0
		}
		mark[num]++
	}
	res := []int{}
	for _, num := range nums2 {
		if cnt, ok := mark[num]; ok && cnt > 0 {
			res = append(res, num)
			mark[num]--
		}
	}
	return res
}

// func main() {
// 	fmt.Println(intersection([]int{1, 2, 2, 3}, []int{2, 2, 2}))
// }
