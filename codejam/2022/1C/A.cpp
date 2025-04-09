#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	string s[n];
	int same[30];
	bool v[30], a[n];
	int cnt = 0;
	for (int i = 0; i < 30; i++) {
		same[i] = 0;
		v[i] = false;
	}
	for (int i = 0; i < n; i++) {
		a[i] = false;
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		if (s[i].length() == 1) {
			same[s[i][0] - 'A'] += s[i].length();
			a[i] = true;
			cnt++;
		}
		for (int j = 1; j < s[i].length(); j++) {
			if (s[i][j] != s[i][j - 1]) {
				break;
			}
			if (j == s[i].length() - 1) {
				same[s[i][0] - 'A'] += s[i].length();
				a[i] = true;
				cnt++;
			}
		}
	}
	
	vector<string> ans = vector<string>(1, "");
	for (int i = cnt; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[j]) {
				continue;
			}
			if (ans.back() == "") {
				ans.back() = s[j];
				for (int k = 0; k < s[j].length(); k++) {
					if (k != 0 && s[j][k] == s[j][k - 1]) {
						continue;
					}
					if (v[s[j][k] - 'A']) {
						cout << "IMPOSSIBLE" << endl;
						return;
					}
					v[s[j][k] - 'A'] = true;
				}
				a[j] = true;
				break;
			}
			if (ans.back()[0] == s[j].back()) {
				for (int k = s[j].length() - 2; k >= 0; k--) {
					if (s[j][k] == s[j][k + 1]) {
						continue;
					}
					if (v[s[j][k] - 'A']) {
						//cout << "!" << endl;
						cout << "IMPOSSIBLE" << endl;
						return;
					}
					v[s[j][k] - 'A'] = true;
				}
				ans.back() = s[j] + ans.back();
				a[j] = true;
				break;
			}
			if (ans.back().back() == s[j][0]) {
				for (int k = 1; k < s[j].length(); k++) {
					if (s[j][k] == s[j][k - 1]) {
						continue;
					}
					if (v[s[j][k] - 'A']) {
						//cout << "@" << endl;
						cout << "IMPOSSIBLE" << endl;
						return;
					}
					v[s[j][k] - 'A'] = true;
				}
				ans.back() = ans.back() + s[j];
				a[j] = true;
				break;
			}
			if (j == n - 1) {
				ans.push_back("");
			}
		}
		if (ans.back() != "") {
			string fr = "", ba = "";
			for (int j = 0; j < same[ans.back()[0] - 'A']; j++) {
				fr.push_back(ans.back()[0]);
			}
			same[ans.back()[0] - 'A'] = 0;
			for (int j = 0; j < same[ans.back().back() - 'A']; j++) {
				ba.push_back(ans.back().back());
			}
			same[ans.back().back() - 'A'] = 0;
			ans.back() = fr + ans.back() + ba;
		} else {
			i--;
		}
	}
	string t = "";
	for (int i = 0; i < 26; i++) {
		if (same[i] > 0) {
			if (v[i]) {
				//cout << "$" << endl;
				cout << "IMPOSSIBLE" << endl;
				return;
			}
			for (int j = 0; j < same[i]; j++) {
				t.push_back('A' + i);
			}
		}
	}
	for (auto x : ans) {
		cout << x;
	}
	cout << t << endl;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
