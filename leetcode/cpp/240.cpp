#include "leetcode.h"

class Solution {
private:
	bool doSearchMatrix(const vector<vector<int>>& matrix, int si, int sj, int ei, int ej, int target)
	{
		if (ei < si || ej < sj) {
			return false;
		}

		int bj = upper_bound(matrix[si].begin() + sj, matrix[si].begin() + ej + 1, target)
					- matrix[si].begin();
		if (bj == sj) {
			return false;
		}
		--bj;

		static auto upper_bound_in_column = [](const vector<vector<int>>& matrix, int column, int low, int high, int target) -> int {
			int ret = high + 1;
			while (low <= high) {
				int mid = (high-low)/2 + low;
				if (matrix[mid][column] > target) {
					ret = mid;
					high = mid - 1;
				} else {
					low = mid + 1;
				}
			}
			return ret;
		};
		int bi = upper_bound_in_column(matrix, bj, si, ei, target);
		--bi;
		if (matrix[bi][bj] == target) {
			return true;
		} else if (bi == ei) {
			return false;
		} else {
			return doSearchMatrix(matrix, bi+1, sj, ei, bj-1, target);
		}
	}
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		int m = matrix.size();
		if (m == 0) {
			return false;
		}
		int n = matrix[0].size();
		if (n == 0) {
			return false;
		}

		return doSearchMatrix(matrix, 0, 0, m-1, n-1, target);
	}
};