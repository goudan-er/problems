#include <iostream>
#include <string>
using namespace std;

/*** core ***/
string encode_space(const string &input)
{
	string output;
	size_t st = input.find_first_not_of(' ', 0);
	while (st != string::npos) {
		size_t ed = input.find_first_of(' ', st);
		if (ed == string::npos) {
			output += input.substr(st);
			break;
		} else {
			output += input.substr(st, ed-st) + "%20";
			st = input.find_first_not_of(' ', ed+1);
		}
	}
	return output;
}
/*** core ***/

int main ()
{
	int cas, len;
	string input;
	cin >> cas;
	for (int i = 0; i < cas; ++i) {
		getline(cin, input);
		cin >> len;
		cout << encode_space(input) << endl;
	}
	return 0;
}