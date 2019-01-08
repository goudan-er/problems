#include "leetcode.h"

class Solution {
public:
	int countNodes(TreeNode* root)
	{
		int hl = 0, hr = 0;
		TreeNode *l = root, *r = root;
		while (l != nullptr) {
			++hl;
			l = l->left;
		}
		while (r != nullptr) {
			++hr;
			r = r->right;
		}
		if (hl == hr) {
			return pow(2, hl) - 1;
		} else {
			return 1 + countNodes(root->left) + countNodes(root->right);
		}
	}
};