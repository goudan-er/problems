#include "leetcode.h"

class Solution {
public:
	vector<string> letterCombinations(string digits)
	{
		vector<string> ret;
		const map<char, string> dialKeys {
			{'2' , "abc"},
			{'3' , "def"},
			{'4' , "ghi"},
			{'5' , "jkl"},
			{'6' , "mno"},
			{'7' , "pqrs"},
			{'8' , "tuv"},
			{'9' , "wxyz"}
		};

		if (digits.empty()) {
			return ret;
		}

		ret.push_back("");
		vector<string> tmpRet;
		for (const char c : digits) {
			auto &&keys = dialKeys.at(c); // universe refernce
			tmpRet.clear();
			for (char key : keys) {
				for (string s : ret) {
					tmpRet.push_back(s+key);
				}
			}
			ret = move(tmpRet);
		}

		return ret;
	}
};