package leetcode

// func isLeaf(leaf *TreeNode) bool {
// 	if leaf != nil && leaf.Left == nil && leaf.Right == nil {
// 		return true
// 	}
// 	return false
// }

func pathSumHelper(root *TreeNode, r int, cur []int, ret [][]int) [][]int {
	if isLeaf(root) && r == root.Val {
		// fmt.Println(cur, root.Val, r)
		ret = append(ret, append([]int{}, append(cur, root.Val)...))
		// fmt.Println(ret)
	} else if root != nil {
		cur = append(cur, root.Val)
		r = r - root.Val
		// fmt.Println(cur, r, ret)
		ret = pathSumHelper(root.Left, r, cur, ret)
		// fmt.Println(cur, r, ret)
		ret = pathSumHelper(root.Right, r, cur, ret)
	}
	return ret
}

func pathSum(root *TreeNode, sum int) [][]int {
	ret := make([][]int, 0)
	cur := make([]int, 0)
	ret = pathSumHelper(root, sum, cur, ret)
	return ret
}
