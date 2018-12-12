#include <bits/stdc++.h>

using namespace std;

#include <string>
#include <iostream>
using namespace std;

class Trie {
public:
	static constexpr int CHARACTER_SIZE = 26;

	class TrieNode {
	public:
		TrieNode* children_[CHARACTER_SIZE]{nullptr};
		int cnt_{0};
	};

public:
	Trie()
	{
		root_ = new TrieNode();
	}

	~Trie()
	{
		for (TrieNode *child : root_->children_) {
			if (child != nullptr)
				delete child;
		}
		delete root_;
		root_ = nullptr;
		
	}

	void insert(const string &word)
	{
		TrieNode *p = root_;
		for (char c : word) {
			int idx = c - 'a';
			if (p->children_[idx] == nullptr) {
				p->children_[idx] = new TrieNode();
			}
			p = p->children_[idx];
			++p->cnt_;
		}
	}

	int count(const string &word)
	{
		TrieNode *p = root_;
		int i = 0, l = word.length();
		for (; i < l; ++i) {
			int idx = word[i] - 'a';
			if (p->children_[idx] == nullptr)
				break;
			p = p->children_[idx];
		}
		
		if (i == l)
			return p->cnt_;
		
		return 0;
	}

private:
	TrieNode *root_;
};

/*
 * Complete the contacts function below.
 */
vector<int> contacts(vector<vector<string>> queries) {
	/*
	 * Write your code here.
	 */
	
	vector<int> ret;
	unique_ptr<Trie> trie(new Trie());
	for (const auto &query : queries) {
		const string &cmd = query[0];
		const string &word = query[1];
		if (cmd == "add") {
			trie->insert(word);
		} else if (cmd == "find") {
			ret.push_back(trie->count(word));
		} else {}
	}

	return ret;

}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int queries_rows;
	cin >> queries_rows;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<vector<string>> queries(queries_rows);
	for (int queries_row_itr = 0; queries_row_itr < queries_rows; queries_row_itr++) {
		queries[queries_row_itr].resize(2);

		for (int queries_column_itr = 0; queries_column_itr < 2; queries_column_itr++) {
			cin >> queries[queries_row_itr][queries_column_itr];
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	vector<int> result = contacts(queries);

	for (int result_itr = 0; result_itr < result.size(); result_itr++) {
		fout << result[result_itr];

		if (result_itr != result.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";

	fout.close();

	return 0;
}