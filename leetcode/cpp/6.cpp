#include "leetcode.h"

class Solution {
private:
	int dx[2] = {1, -1};
	int dy[2] = {0, 1};
	typedef int FLAG;
	typedef tuple<int, int, FLAG> tp3;
	inline tp3 getNextPos(int ci, int cj, int numRows, FLAG flag)
	{
		int try_i = ci + dx[flag];
		int try_j = cj + dy[flag];

		if (try_i < 0 || try_i >= numRows) {
			flag = 1 - flag;
			try_i = ci + dx[flag];
			try_j = cj + dy[flag];
		}
		
		return make_tuple(try_i, try_j, flag);
	}

public:
	string convert(string s, int numRows)
	{
		if (numRows == 1)
			return s;
		
		string ans;
		map<pair<int, int>, char> helpAns;
		int ci = -1, cj = 0;
		FLAG flag = 0;
		for (char c : s) {
			tp3 tmp = getNextPos(ci, cj, numRows, flag);
			tie(ci, cj, flag) = tmp;
			// cout << ci << ' ' << cj << ' ' << c << endl;
			helpAns.insert({{ci, cj}, c});
		}

		for (const auto &idxWithChar : helpAns) {
			// cout << idxWithChar.first.first << ' ' << idxWithChar.first.second << ' ' << idxWithChar.second << endl;
			ans.push_back(idxWithChar.second);
		}

		return ans;
	}
};