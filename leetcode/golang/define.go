package leetcode

type TreeNode struct {
	val   int
	left  TreeNode
	right TreeNode
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
