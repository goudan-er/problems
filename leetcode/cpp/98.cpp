#include "leetcode.h"

class Solution {
public:
	bool isValidBST(TreeNode* root, TreeNode* minNode = nullptr, TreeNode* maxNode = nullptr)
	{
		if (root == nullptr) return true;
		else
			return (!minNode || root->val > minNode->val)
			&& (!maxNode || root->val < maxNode->val)
			&& isValidBST(root->left, minNode, root)
			&& isValidBST(root->right, root, maxNode);
	}
};