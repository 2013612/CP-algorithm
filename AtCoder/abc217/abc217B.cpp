#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string s[3];
string t[] = {"ABC", "ARC", "AGC", "AHC"};
int main() {
	cin >> s[0] >> s[1] >> s[2];
	sort(s, s + 3);
	sort(t, t + 4);
	for (int i = 0; i < 3; i++) {
		if (s[i] != t[i]) {
			cout << t[i] << endl;
			break;
		}
		if (i == 2) {
			cout << t[3] << endl;
		}
	}
	return 0;
}
