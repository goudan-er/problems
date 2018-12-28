package leetcode

func searchMatrix(matrix [][]int, target int) bool {
	m := len(matrix)
	if m == 0 {
		return false
	}
	n := len(matrix[0])
	if n == 0 {
		return false
	}
	l, r := 0, m*n-1
	for l <= r {
		mid := (r-l)/2 + l
		i, j := mid/n, mid%n
		if target == matrix[i][j] {
			return true
		} else if target < matrix[i][j] {
			r = mid - 1
		} else { // target > matrix[i][j]
			l = mid + 1
		}
	}
	return false
}
