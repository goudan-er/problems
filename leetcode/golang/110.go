package leetcode

// func abs(x int) int {
// 	if x < 0 {
// 		return -x
// 	}
// 	return x
// }

// func max(x, y int) int {
// 	if x > y {
// 		return x
// 	}
// 	return y
// }

func check(root *TreeNode) (bool, int) {
	if root == nil {
		return true, 0
	}
	isLeftBalanced, leftMaxDepth := check(root.Left)
	isRightBalanced, rightMaxDepth := check(root.Right)
	return isLeftBalanced && isRightBalanced && abs(leftMaxDepth-rightMaxDepth) <= 1, max(leftMaxDepth, rightMaxDepth) + 1
}

func isBalanced(root *TreeNode) bool {
	ret, _ := check(root)
	return ret
}
