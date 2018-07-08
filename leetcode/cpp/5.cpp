#include "leetcode.h"

class Solution {
private:
	int getlongestPalindrome(const string &s, int &l, int &r)
	{
		int len = s.length();
		while (l-1 >= 0 && r+1 < len) {
			if (s[l-1] != s[r+1])
				break;
			--l;
			++r;
		}
		return r-l+1;
	}

	void updateAns(const string &s, const int l, const int r, string &ans, int &ansLen)
	{
		ans = s.substr(l, r-l+1);
		ansLen = r - l + 1;
	}

public:
	string longestPalindrome(string s)
	{
		int len = s.length();
		string ans;
		int ansLen = 0;
		for (int mid = 0; mid < len; ++mid) {
			
			int l = mid, r = mid;
			int tmpLen = getlongestPalindrome(s, l, r);
			if (tmpLen > ansLen)
				updateAns(s, l, r, ans, ansLen);

			l = mid, r = mid+1;
			if (r < len && s[l] == s[r]) {
				tmpLen = getlongestPalindrome(s, l, r);
				if (tmpLen > ansLen)
					updateAns(s, l, r, ans, ansLen);
			}
		}

		return ans;
	}
};