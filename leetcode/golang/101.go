package leetcode

func checkSymmetric(left, right *TreeNode) bool {
	if left == nil && right == nil {
		return true
	} else if left != nil && right != nil {
		return left.Val == right.Val && checkSymmetric(left.Left, right.Right) && checkSymmetric(left.Right, right.Left)
	}
	return false
}

func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return checkSymmetric(root.Left, root.Right)
}
