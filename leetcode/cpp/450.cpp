#include "leetcode.h"

class Solution {
private:
    TreeNode* deleteRoot(TreeNode* root)
    {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->right == nullptr) {
            TreeNode* ret = root->left;
            delete root;
            return ret;
        } else {
            TreeNode* rightMinNode = root->right;
            while (rightMinNode->left != nullptr) {
                rightMinNode = rightMinNode->left;
            }
            root->val = rightMinNode->val;
            root->right = deleteNode(root->right, rightMinNode->val);
            return root;
        }
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if (root == nullptr) return nullptr;

        if (root->val == key) {
            return deleteRoot(root);
        } else {
            if (key < root->val) {
                root->left = deleteNode(root->left, key);
            } else {
                root->right = deleteNode(root->right, key);
            }
            return root;
        }
    }
};