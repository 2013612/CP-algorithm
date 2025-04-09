#include<iostream>
#include<string>
using namespace std;

string S, ans;
int count;
int main() {
	cin >> S;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '{') {
			count++;
		} else if (S[i] == '}') {
			count--;
		} else if (S[i] == ':' && count == 1) {
			ans = "dict";
		}
	}
	if (S == "{}") {
		ans = "dict";
	}
	if (ans != "dict") {
		ans = "set";
	}
	cout << ans << endl;
	return 0;
}
