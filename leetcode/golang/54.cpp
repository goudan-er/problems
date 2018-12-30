#include "leetcode.h"

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ret;
		int m = matrix.size();
		if (m == 0) {
			return ret;
		}
		int n = matrix[0].size();
		if (n == 0) {
			return ret;
		}
		ret.reserve(m*n);
		static const int diri[] = {0, 1, 0, -1};
		static const int dirj[] = {1, 0, -1, 0};
		set<pair<int, int>> flag;
		// use static for this lambda function will cause unexpected TLE
		const auto getNext = [m, n, &diri, &dirj, &flag](int &ci, int &cj, int &dirIdx) {
			while (1) {
				int ti = ci + diri[dirIdx];
				int tj = cj + dirj[dirIdx];
				if (ti >= 0 && ti < m && tj >= 0 && tj < n && flag.find(pair<int, int>{ti, tj}) == flag.end()) {
					ci = ti;
					cj = tj;
					return ;
				}
				dirIdx = (dirIdx + 1) % 4;
			}
		};
		int i = 0, j = 0, dirIdx = 0;
		while (1) {
			ret.push_back(matrix[i][j]);
			flag.insert(pair<int, int>{i, j});
			if (flag.size() == m*n)
				break;
			getNext(i, j, dirIdx);
			// printf("%d %d %d\n", i, j, dirIdx);
		}
		return ret;
	}
};