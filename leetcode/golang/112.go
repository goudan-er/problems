package leetcode

func isLeaf(leaf *TreeNode) bool {
	if leaf != nil && leaf.Left == nil && leaf.Right == nil {
		return true
	}
	return false
}

func hasPathSum(root *TreeNode, sum int) bool {
	if root == nil {
		return false
	} else if isLeaf(root) {
		if root.Val == sum {
			return true
		}
		return false
	}
	return hasPathSum(root.Left, sum-root.Val) || hasPathSum(root.Right, sum-root.Val)
}
