#include "leetcode.h"

class Solution {
public:
    int sumNumbers(TreeNode* root, int cur = 0, int sum = 0)
    {
        if (root == nullptr) {
            return sum;
        } else if (root->left == nullptr && root->right == nullptr) {
            return sum + (cur * 10 + root->val);
        }
        else {
            return sumNumbers(root->left, cur * 10 + root->val, sum) + sumNumbers(root->right, cur * 10 + root->val, sum);
        }
    }
};