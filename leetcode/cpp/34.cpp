#include "leetcode.h"

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		auto range = std::equal_range(nums.begin(), nums.end(), target);
		return range.first == range.second ? vector<int>{-1, -1} : vector<int>{range.first - nums.begin(), range.second - nums.begin() - 1};
	}
};