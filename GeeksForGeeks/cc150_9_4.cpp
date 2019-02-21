/**
 * @author [gg]
 * @email [llyanwenyuan@gmail.com]
 * @create date 2019-02-21 01:43:57
 * @modify date 2019-02-21 01:43:57
 * @desc [subset https://practice.geeksforgeeks.org/problems/subsets/0]
 */

#include <bits/stdc++.h>
using namespace std;

#define clr(x,c) memset(x, c, sizeof(x))
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define psi pair<string, int>
#define inf 0x3f3f3f3f
typedef long long lld;

static unsigned int g_seed = 0;
inline void fastsrand()
{
   g_seed = (unsigned int)time(0);
}
inline int fastrand()
{
   g_seed = (214013 * g_seed + 2531011);
	return (g_seed >> 16) & 0x7FFF;
}

void dfs(const vector<int> &nums, int idx, vector<int> &cur, vector<vector<int>> &ret)
{
    ret.push_back(cur);
    int pre_idx = -1;
    for (int i = idx; i < nums.size(); ++i) {
        if (pre_idx == -1 || nums[pre_idx] != nums[i]) {
            cur.push_back(nums[i]);
            dfs(nums, i+1, cur, ret);
            cur.pop_back();
            pre_idx = i;
        }
    }
}

int main ()
{
    int cases, n;
    vector<int> nums;
    cin >> cases;
    while (cases--) {
        cin >> n;
        nums.clear();
        nums.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(nums, 0, cur, ans);
        for (const vector<int> &v : ans) {
            cout << "(";
            if (!v.empty()) {
                for (int i = 0; i < v.size()-1; ++i) {
                    cout << v[i] << " ";
                }
                cout << v.back();
            }
            cout << ")";
        }
        cout << endl;
    }
    return 0;
}