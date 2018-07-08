package leetcode

func find(nums []int, key int) int {
	for i, val := range nums {
		if val == key {
			return i
		}
	}
	return -1
}

func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(preorder) == 0 {
		return nil
	} else {
		root := preorder[0]
		pos := find(inorder, root)
		if pos == -1 {
			panic("inpur error")
		}
		left := buildTree(preorder[1:pos+1], inorder[:pos])
		right := buildTree(preorder[pos+1:], inorder[pos+1:])
		return &TreeNode{root, left, right}
	}
}
