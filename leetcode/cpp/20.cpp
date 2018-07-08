#include "leetcode.h"

class Solution {
private:
	inline bool isLeft(char c)
	{
		return c == '(' || c == '[' || c == '{';
	}
	inline bool isPair(char l, char r)
	{
		return	(l == '(' && r == ')')
				|| (l == '[' && r == ']')
				|| (l == '{' && r == ']');
	}
public:
	bool isValid(string s)
	{
		stack<char> stk;
		for (char c : s) {
			if (isLeft(c) || stk.empty() || 
				!isPair(stk.top(), c))
				stk.push(c);
			else stk.pop();
		}
		return stk.empty();
	}
};