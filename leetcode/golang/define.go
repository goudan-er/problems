package leetcode

type TreeNode struct {
	val   int
	left  *TreeNode
	right *TreeNode
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
