#include "leetcode.h"

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		queue<int> window;
		int curSum = 0, ret = INT_MAX;
		for (int x : nums) {
			while (!window.empty() && curSum - window.front() + x >= s) {
				curSum -= window.front();
				window.pop();
			}
			window.push(x);
			curSum += x;
			if (curSum >= s)
				ret = min(ret, static_cast<int>(window.size()));
		}
		return ret == INT_MAX ? 0 : ret;
	}
};