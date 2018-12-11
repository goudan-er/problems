#include "leetcode.h"

class Solution {
private:
	int findKthNumber(int k, const vector<int> &nums1, const int s1, const int e1,
						const vector<int> &nums2, const int s2, const int e2) // [s, e), don't do out of access check
	{
		if (e1 <= s1) {
			return nums2[s2+k-1];
		}
		if (e2 <= s2) {
			return nums1[s1+k-1];
		}
		int mid1 = (e1 - s1 - 1) / 2 + s1;
		int lcnt1 = mid1 - s1 + 1;
		int mid1Value = nums1[mid1];
		int idx2 = std::upper_bound(nums2.begin() + s2, nums2.begin() + e2, mid1Value) 
					- nums2.begin() - 1;
		int lcnt2 = idx2 - s2 + 1;
		if (lcnt1 + lcnt2 == k) {
			return mid1Value;
		} else if (lcnt1 + lcnt2 > k) {
			return findKthNumber(k, nums1, s1, mid1, nums2, s2, idx2+1);
		} else { // (lcnt1 + lcnt2 < k) 
			return findKthNumber(k-lcnt1-lcnt2, nums1, mid1+1, e1, nums2, idx2+1, e2);
		}
	}

public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int total = nums1.size() + nums2.size();
		if (total%2 == 0) {
			int m1 = findKthNumber(total/2, nums1, 0, nums1.size(), nums2, 0, nums2.size());
			int m2 = findKthNumber(total/2+1, nums1, 0, nums1.size(), nums2, 0, nums2.size());
			return 0.5 * (m1+m2);
		} else {
			return findKthNumber(total/2+1, nums1, 0, nums1.size(), nums2, 0, nums2.size());
		}
	}
};