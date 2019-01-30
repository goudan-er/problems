/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

#include "leetcode.h"

class Solution {
public:
	// void connect(TreeLinkNode *root)
	// {
	// 	if (root == nullptr)
	// 		return;
		
	// 	typedef pair<int, TreeLinkNode*> Ele;
	// 	queue<Ele> que;
	// 	que.push(Ele{1, root});
	// 	TreeLinkNode *preNode = root;
	// 	int preLevel = 0;
	// 	while (!que.empty()) {
	// 		Ele& e = que.front();
	// 		que.pop();
	// 		TreeLinkNode *cur = e.second;
	// 		int curLevel = e.first, nextLevel = e.first + 1;
	// 		if (preLevel == curLevel) {
	// 			preNode->next = cur;
	// 		} else {
	// 			preNode->next = nullptr;
	// 		}
	// 		if (cur->left != nullptr) {
	// 			que.push(Ele{nextLevel, cur->left});
	// 		}
	// 		if (cur->right != nullptr) {
	// 			que.push(Ele{nextLevel, cur->right});
	// 		}
	// 		preNode = cur;
	// 		preLevel = e.first;
	// 	}
	// }

	// void connect(TreeLinkNode *root)
	// {
	// 	if (root == nullptr)
	// 		return;
	// 	while (root->left) {
	// 		TreeLinkNode *cur = root;
	// 		while (cur) {
	// 			cur->left->next = cur->right;
	// 			if (cur->right && cur->next) {
	// 				cur->right->next = cur->next->left;
	// 			}
	// 			cur = cur->next;
	// 		}
	// 		root = root->left;
	// 	}
	// }

	void connect(TreeLinkNode *root)
	{
		if (root == nullptr)
			return;

		if (root->left) {
			root->left->next = root->right;
			if (root->right && root->next) {
				root->right->next = root->next->left;
			}
		}

		connect(root->left);
		connect(root->right);
	}
};