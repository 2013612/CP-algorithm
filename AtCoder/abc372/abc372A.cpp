#include<iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	string ans = "";
	for (auto c: s) {
		if (c != '.') {
			ans.push_back(c);
		}
	}
	cout << ans << endl;
	return 0;
}