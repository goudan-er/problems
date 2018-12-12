#include <string>
#include <iostream>
using namespace std;

class Trie {
public:
	static constexpr int CHARACTER_SIZE = 256;

	class TrieNode {
	public:
		TrieNode* children_[CHARACTER_SIZE]{nullptr};
		bool is_terminal_{false};
	};

public:
	Trie()
	{
		root_ = new TrieNode();
		root_->is_terminal_ = true;
	}

	~Trie()
	{
		if (!root_->is_terminal_) {
			for (TrieNode *child : root_->children_) {
				if (child != nullptr)
					delete child;
			}
		}
		delete root_;
		root_ = nullptr;
		
	}

	void insert(const string &word)
	{
		
		TrieNode *p = root_;
		for (char c : word) {
			if (p->children_[c] == nullptr) {
				p->children_[c] = new TrieNode();
			}
			p = p->children_[c];
		}
		p->is_terminal_ = true;
	}

	bool find(const string &word)
	{
		TrieNode *p = root_;
		int i = 0, l = word.length();
		for (; i < l; ++i) {
			if (p->children_[word[i]] == nullptr)
				break;
			p = p->children_[word[i]];
		}
		
		if (i == l && p->is_terminal_)
			return true;
		
		return false;
	}

private:
	TrieNode *root_;
};