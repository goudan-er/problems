package leetcode

func sortedArrayToBST(nums []int) *TreeNode {
	n := len(nums)
	if n == 0 {
		return nil
	}
	mid := n / 2
	root := new(TreeNode{Left: nil, Right: nil, Val: nums[mid]})
	root.Left = sortedArrayToBST(nums[0:mid])
	root.Right = sortedArrayToBST(nums[mid+1:])
	return root
}
