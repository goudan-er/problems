package leetcode

func maxArea(height []int) int {
	l := len(height)
	if l == 2 {
		return min(height[0], height[1])
	}
	area := (l - 1) * min(height[0], height[l-1])
	if height[0] < height[l-1] {
		return max(area, maxArea(height[1:]))
	}
	return max(area, maxArea(height[0:l-1]))
}
