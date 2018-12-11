#include "leetcode.h"

class Solution {
public:
	string simplifyPath(string path)
	{
		static const string one_dot = ".";
		static const string two_dots = "..";
		deque<string> dirs;
		int st = path.find_first_of('/', 0);
		while (st != string::npos) {
			int nt = path.find_first_of('/', st+1);
			string subpath;
			if (nt != string::npos) subpath = path.substr(st+1, nt-st-1);
			else subpath = path.substr(st+1);
			if (subpath == two_dots) {
				if (!dirs.empty()) dirs.pop_back();
			} else if (!subpath.empty() && subpath != one_dot) {
				dirs.emplace_back(subpath);
			} else {}
			st = nt;
		}

		string ret;
		while (!dirs.empty()) {
			ret += "/" + dirs.front();
			dirs.pop_front();
		}

		return ret.empty() ? "/" : ret;
	}
};