package leetcode

type TreeNode struct {
	Val   int
	left  *TreeNode
	right *TreeNode
}

type Interval struct {
	Start int
	End   int
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
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
