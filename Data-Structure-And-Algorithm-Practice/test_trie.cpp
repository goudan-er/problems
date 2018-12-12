#include "Trie.h"

#include <iostream>
using namespace std;

int main ()
{
	unique_ptr<Trie> trie(new Trie());

	string keys[] = {"the", "a", "there", 
					"answer", "any", "by", 
					 "bye", "their" }; 

	for (const string &key : keys) {
		trie->insert(key);
	}

	trie->find("the") ? cout << "Yes\n" : cout << "No\n";
	trie->find("these") ? cout << "Yes\n" : cout << "No\n";
	trie->find("he") ? cout << "Yes\n" : cout << "No\n";
	trie->find("an") ? cout << "Yes\n" : cout << "No\n";
	trie->find("any") ? cout << "Yes\n" : cout << "No\n";
	trie->find("") ? cout << "Yes\n" : cout << "No\n";

	return 0;
}