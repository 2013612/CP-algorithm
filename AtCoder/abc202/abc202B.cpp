#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string S, ans;
int main() {
	cin >> S;
	for (int i = S.length() - 1; i >= 0; i--) {
		if (S[i] == '6') {
			ans.push_back('9');
		} else if (S[i] == '9') {
			ans.push_back('6');
		} else {
			ans.push_back(S[i]);
		}
	}
	cout << ans << endl;
	return 0;
}
