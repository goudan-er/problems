package leetcode

// func isLeaf(leaf *TreeNode) bool {
// 	if leaf != nil && leaf.Left == nil && leaf.Right == nil {
// 		return true
// 	}
// 	return false
// }

func flattenHelper(root *TreeNode) (*TreeNode, *TreeNode) {
	if root == nil || isLeaf(root) {
		return root, root
	}
	lHead, lTail := flattenHelper(root.Left)
	rHead, rTail := flattenHelper(root.Right)
	root.Left = nil
	root.Right = nil
	head, tail := root, root
	if rTail != nil {
		tail = rTail
	} else {
		tail = lTail
	}
	if lTail != nil {
		lTail.Right = rHead
		head.Right = lHead
	} else {
		head.Right = rHead
	}
	return head, tail
}

func flatten(root *TreeNode) {
	flattenHelper(root)
}
