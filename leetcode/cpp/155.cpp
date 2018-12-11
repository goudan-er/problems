#include "leetcode.h"

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {}
	
	void push(int x)
	{
		numsStk.push(x);
		if (minStk.empty())	{
			minStk.push(x);
		} else {
			minStk.push(std::min(x, minStk.top()));
		}
	}
	
	void pop()
	{
		if (!numsStk.empty())
			numsStk.pop();
		if (!minStk.empty())
			minStk.pop();	
	}
	
	int top()
	{
		if (!numsStk.empty())
			return numsStk.top();
		return INT_MAX;	
	}
	
	int getMin()
	{
		if (!minStk.empty())
			return minStk.top();
		return INT_MIN;
	}

private:
	stack<int> numsStk;
	stack<int> minStk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */