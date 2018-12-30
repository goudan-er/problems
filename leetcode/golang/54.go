package leetcode

func spiralOrder(matrix [][]int) []int {
	ret := []int{}
	m := len(matrix)
	if m == 0 {
		return ret
	}
	n := len(matrix[0])
	if n == 0 {
		return ret
	}
	flag := make([][]int, m)
	for r := 0; r < m; r++ {
		flag[r] = make([]int, n)
	}
	diry := []int{0, 1, 0, -1}
	dirx := []int{1, 0, -1, 0}
	getNext := func(x, y, dirIdx int) (int, int, int) {
		for {
			tx, ty := x+dirx[dirIdx], y+diry[dirIdx]
			if tx >= 0 && tx < n && ty >= 0 && ty < m && flag[ty][tx] == 0 {
				return tx, ty, dirIdx
			}
			dirIdx = (dirIdx + 1) % 4
		}
	}
	var x, y, dirIdx, cnt int
	for {
		ret = append(ret, matrix[y][x])
		flag[y][x] = 1
		cnt++
		if cnt == m*n {
			break
		}
		x, y, dirIdx = getNext(x, y, dirIdx)
	}
	return ret
}
