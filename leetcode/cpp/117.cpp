#include "leetcode.h"

class Solution {
public:
	void connect(TreeLinkNode *root)
	{
		if (root == nullptr)
			return;
		
		typedef pair<int, TreeLinkNode*> Ele;
		queue<Ele> que;
		que.push(Ele{1, root});
		TreeLinkNode *preNode = root;
		int preLevel = 0;
		while (!que.empty()) {
			Ele& e = que.front();
			que.pop();
			TreeLinkNode *cur = e.second;
			int curLevel = e.first, nextLevel = e.first + 1;
			if (preLevel == curLevel) {
				preNode->next = cur;
			} else {
				preNode->next = nullptr;
			}
			if (cur->left != nullptr) {
				que.push(Ele{nextLevel, cur->left});
			}
			if (cur->right != nullptr) {
				que.push(Ele{nextLevel, cur->right});
			}
			preNode = cur;
			preLevel = e.first;
		}
	}
};