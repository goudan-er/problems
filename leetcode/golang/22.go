package leetcode

func generateParenthesisHelper(n int, left int, right int, cur string, result *[]string) {
	if left == n && right == n {
		*result = append(*result, cur)
	}

	if left < n {
		generateParenthesisHelper(n, left+1, right, cur+"(", result)
	}

	if right < left {
		generateParenthesisHelper(n, left, right+1, cur+")", result)
	}
}

func generateParenthesis(n int) []string {
	result := []string{}
	generateParenthesisHelper(n, 0, 0, "", &result)
	return result
}
