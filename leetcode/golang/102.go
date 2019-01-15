package leetcode

func levelOrderHelper(root *TreeNode, level int, ret [][]int) [][]int {
	if root != nil {
		if len(ret) < level {
			newSlice := make([]int, 0)
			ret = append(ret, newSlice)
		}
		ret[level-1] = append(ret[level-1], root.Val)
		ret = levelOrderHelper(root.Left, level+1, ret)
		ret = levelOrderHelper(root.Right, level+1, ret)
	}
	return ret
}

func levelOrder(root *TreeNode) [][]int {
	ret := make([][]int, 0)
	ret = levelOrderHelper(root, 1, ret)
	return ret
}
