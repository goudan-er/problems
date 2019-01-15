package leetcode

func zigzagLevelOrderHelper(root *TreeNode, level int, ret [][]int) [][]int {
	if root != nil {
		if len(ret) < level {
			ret = append(ret, []int{})
		}
		if level%2 == 1 {
			ret[level-1] = append(ret[level-1], root.Val)
		} else {
			ret[level-1] = append([]int{root.Val}, ret[level-1]...)
		}
		ret = zigzagLevelOrderHelper(root.Left, level+1, ret)
		ret = zigzagLevelOrderHelper(root.Right, level+1, ret)
	}
	return ret
}

func zigzagLevelOrder(root *TreeNode) [][]int {
	ret := make([][]int, 0)
	ret = zigzagLevelOrderHelper(root, 1, ret)
	return ret
}
