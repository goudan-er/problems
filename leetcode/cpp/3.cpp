#include "leetcode.h"

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.length() == 0 || s.length() == 1)
			return s.length();

		vector<int> pre_pos;
		pre_pos.resize(s.length());
		vector<int> flag;
		flag.resize(256, -1);
		for (int i = 0; i < s.length(); ++i) {
			char c  = s[i];
			pre_pos[i] = flag[c-'a'];
			flag[c-'a'] = i;
		}
        
		int ans = 0, start = 0;
		for (int i = 0; i < s.length(); ++i) {
			int pre_pos_si = pre_pos[i];
			if (pre_pos_si < start) {
				ans = max(ans, i - start + 1);
			} else { // pre_pos_si > start
				ans = max(ans, i - pre_pos_si);
				start = pre_pos_si + 1;
			}
		}

		return ans;
	}
};