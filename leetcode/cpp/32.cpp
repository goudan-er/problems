#include "leetcode.h"

class Solution {
public:
	int longestValidParentheses(string s)
	{	
		stack<int> stk;
		int len = s.length();
		for (int i = 0; i < len; ++i) {
			char c = s[i];
			if (c == '(')
				stk.push(i);
			else if (stk.empty() || stk.top() != '(')
				stk.push(i);
			else // !stk.empty() && stk.top() == ')'
				stk.pop();
		}

		if (stk.empty())
			return len;
		else {
			int ans = 0;
			int idx1 = -1, idx2;
			while (!stk.empty()) {
				idx2 = stk.top();
				stk.pop();
				ans = max(ans, idx2-idx1-1);
				idx1 = idx2;
			}
			return ans;
		}
	}
};