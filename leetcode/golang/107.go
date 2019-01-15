package leetcode

func levelOrderBottomHelper(root *TreeNode, level int, ret [][]int) [][]int {
	if root != nil {
		if len(ret) < level {
			s := make([]int, 0)
			ret = append([][]int{s}, ret...)
		}
		idx := len(ret) - level
		ret[idx] = append(ret[idx], root.Val)
		ret = levelOrderBottomHelper(root.Left, level+1, ret)
		ret = levelOrderBottomHelper(root.Right, level+1, ret)
	}
	return ret
}

func levelOrderBottom(root *TreeNode) [][]int {
	ret := make([][]int, 0)
	ret = levelOrderBottomHelper(root, 1, ret)
	return ret
}
