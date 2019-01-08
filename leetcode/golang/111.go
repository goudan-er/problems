package leetcode

// func min(x, y int) int {
// 	if x < y {
// 		return x
// 	}
// 	return y
// }

func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	} else if root.Left == nil {
		return 1 + minDepth(root.Right)
	} else if root.Right == nil {
		return 1 + minDepth(root.Left)
	}
	return 1 + min(minDepth(root.Left), minDepth(root.Right))
}
