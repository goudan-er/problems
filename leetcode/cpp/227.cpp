#include "leetcode.h"

class Solution {
private:
	std::string& trim(std::string& s) 
	{
		if (s.empty())
			return s;
	
		s.erase(0,s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);
		return s;
	}

	inline int calculate(int a, int b, char op)
	{
		switch (op)
		{
			case '+': return a+b;
			case '-': return a-b;
			case '*': return a*b;
			case '/': return a/b;
		}
		return 0;
	}

	inline int priority(char op)
	{
		if (op == '(') return 0;
		if (op == ')') return 1;
		if (op == '+' || op == '-') return 2;
		if (op == '*' || op == '/') return 3;
		return -1;
	}

public:
	int calculate(string s)
	{
		stack<int> numStk;
		stack<char> opStk;
		opStk.push('(');
		s.push_back(')');
		int pre = -1, next = s.find_first_of("+-*/()", pre+1);
		while (next != string::npos) {
			string numStr = s.substr(pre+1, next-pre-1);
			trim(numStr);
			int num = atoi(numStr.c_str());
			char op = s[next], preOp = opStk.top();
			// printf("op=%c, preOp=%c, num=%d\n", op, preOp, num);
			while (priority(op) - priority(preOp) <= 0) {
				int preNum = numStk.top();
				numStk.pop();
				num = calculate(preNum, num, preOp);
				// printf("cal: preOp=%c, preNum=%d, num=%d\n", preOp, preNum, num);
				opStk.pop();
				preOp = opStk.top();
			}
			// printf("push: op=%c, num=%d\n", op, num);
			opStk.push(op);
			numStk.push(num);
			pre = next;
			next = s.find_first_of("+-*/()", pre+1);
		}
		return numStk.top();
	}
};