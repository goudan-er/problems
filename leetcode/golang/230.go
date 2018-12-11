package leetcode

func kthSmallest(root *TreeNode, k int) int {

	if root == nil {
		return 0
	}

	LeftCnt := count(root.Left)
	if k == LeftCnt+1 {
		return root.Val
	} else if k <= LeftCnt {
		return kthSmallest(root.Left, k)
	} else {
		return kthSmallest(root.Right, k-LeftCnt-1)
	}
}

func count(root *TreeNode) int {
	if root == nil {
		return 0
	}
	return 1 + count(root.Left) + count(root.Right)
}
