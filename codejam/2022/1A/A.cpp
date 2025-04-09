#include<iostream>
using namespace std;

int t;

void solve() {
	string s;
	cin >> s;
	string ans = "";
	string temp = "";
	for (int i = 0; i < s.length(); i++) {
		if (temp.empty()) {
			temp.push_back(s[i]);
			continue;
		}
		if (temp.back() > s[i]) {
			ans += temp;
			temp = s[i];
		} else if (temp.back() < s[i]) {
			temp += temp;
			ans += temp;
			temp = s[i];
		} else {
			temp.push_back(s[i]);
		}
	}
	ans += temp;
	cout << ans << endl;
}

int main() {
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
