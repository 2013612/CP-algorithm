#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

unordered_set<string> us;

void gen(string s, int target) {
	if (s.length() == target) {
		us.insert(s);
		return;
	}
	bool v[target];
	for (int i = 0; i < target; i++) {
		v[i] = false;
	}
	for (int i = 0; i < s.length(); i++) {
		v[s[i] - '0'] = true;
	}
	for (int i = 0; i < target; i++) {
		if (!v[i]) {
			s.push_back('0' + i);
			gen(s, target);
			s.pop_back();
		}
	}
}

void solve() {
	int n;
	scanf("%d", &n);
	us.clear();
	gen("", n);
	string s[n];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (auto se : us) {
		string ans = "";
		for (int i = 0; i < se.length(); i++) {
			ans += s[se[i] - '0'];
		}
		bool can = true;
		bool v[30];
		for (int i = 0; i < 30; i++) {
			v[i] = false;
		}
		for (int i = 0; i < ans.size(); i++) {
			if (i == 0) {
				v[ans[i] - 'A'] = true;
			} else {
				if (ans[i] == ans[i - 1]) {
					continue;
				}
				if (v[ans[i] - 'A']) {
					can = false;
					break;
				}
				v[ans[i] - 'A'] = true;
			}
			if (!can) {
				break;
			}
		}
		if (can) {
			cout << ans << endl;
			return;
		}
	}
	printf("IMPOSSIBLE\n");
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
