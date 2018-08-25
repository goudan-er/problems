#include "leetcode.h"

class Solution {
public:
	vector<string> generateParenthesis(int n)
	{
		vector<string> result;
		queue<tuple<string, int, int>> q;
		q.push(make_tuple("", 0, 0));
		while (!q.empty()) {
			auto t = q.front();
			q.pop();
			string cur = get<0>(t);
			int left = get<1>(t);
			int right = get<2>(t);
			if (left == n && right == n) {
				result.push_back(cur);
			} else {
				if (left < n) {
					q.push(make_tuple(cur+"(", left+1, right));
				}
				if (right < left) {
					q.push(make_tuple(cur+")", left, right+1));
				}
			}
		}

		return result;
	}
};