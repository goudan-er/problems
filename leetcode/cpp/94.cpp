#include "leetcode.h"

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> ret;
		if (root == nullptr) {
			return ret;
		}
		stack<TreeNode*> stkHelper;
		TreeNode *cur = root;
		while (!stkHelper.empty() || cur != nullptr) {
			if (cur != nullptr) {
				stkHelper.push(cur);
				cur = cur->left;
			} else {
				TreeNode *t = stkHelper.top();
				ret.push_back(t->val);
				stkHelper.pop();
				cur = t->right;
			}
		}
		return ret;
	}
};