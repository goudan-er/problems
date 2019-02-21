/**
 * @author [gg]
 * @email [llyanwenyuan@gmail.com]
 * @create date 2019-02-22 01:45:26
 * @modify date 2019-02-22 01:45:26
 * @desc [https://practice.geeksforgeeks.org/problems/combination-sum/0]
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

void print(const vector<vector<int>> &v)
{
    if (v.empty()) {
        cout << "Empty" << endl;
    } else {
        for (const auto &vv : v) {
            cout << "(" << vv[0];
            for (int i = 1; i < vv.size(); ++i) {
                cout << " " << vv[i];
            }
            cout << ")";
        }
        cout << endl;
    }
}

void dfs(const vector<int> &nums, int idx, vector<int> &cur, vector<vector<int>> &ans, int r)
{
    if (r == 0) {
        ans.push_back(cur);
        return;
    }
    
    for (int i = idx; i < nums.size(); ++i) {
        if (r >= nums[i]) {
            cur.push_back(nums[i]);
            dfs(nums, i, cur, ans, r-nums[i]);
            cur.pop_back();
        }
    }
}

int main ()
{
    int cases;
    cin >> cases;
    while (cases--) {
        int n, sum;
        cin >> n;
        vector<int> nums; nums.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        cin >> sum;
        sort(nums.begin(), nums.end());
        auto last = unique(nums.begin(), nums.end());
        nums.erase(last, nums.end());
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(nums, 0, cur, ans, sum);
        print(ans);
    }
    return 0;
}