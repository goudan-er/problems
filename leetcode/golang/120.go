package leetcode

import "math"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func doMaxPathSum(root *TreeNode) (maxPath, maxRootPath int) {
	if root == nil {
		return math.MinInt32, 0
	}

	lMaxPath, lMaxRootPath := doMaxPathSum(root.Left)
	rMaxPath, rMaxRootPath := doMaxPathSum(root.Right)

	maxRootPath = max(max(lMaxRootPath, rMaxRootPath), 0) + root.Val
	maxPath = max(maxRootPath, max(lMaxPath, rMaxPath))
	if lMaxRootPath > 0 && rMaxRootPath > 0 {
		maxPath = max(maxPath, lMaxRootPath+rMaxRootPath+root.Val)
	} else {
		maxPath = max(maxPath, max(lMaxRootPath, rMaxRootPath)+root.Val)
	}
	return maxPath, maxRootPath
}

func maxPathSum(root *TreeNode) int {
	maxPath, _ := doMaxPathSum(root)
	return maxPath
}
