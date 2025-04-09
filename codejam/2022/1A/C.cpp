#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

int t;
string num[11] = {"00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10"};

void solve(int t) {
	int e, w, a[103][103];
	scanf("%d %d", &e, &w);
	for (int i = 1; i <= e; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	queue<string> q;
	unordered_map<string, int> ans;
	q.push(num[0]);
	ans[num[0]] = 0;
	while (ans.count(num[e]) == 0) {
		string s = q.front();
		q.pop();
		int cnt[3] = {0, 0, 0};
		for (int i = 2; i < s.length(); i++) {
			cnt[s[i] - '0']++;
		}
		int n = stoi(s.substr(0, 2));
		if (n == e) {
			string ns = s.substr(0, s.length() - 1);
			if (!ans.count(ns)) {
				ans[ns] = ans[s] + 1;
				q.push(ns);
			}
		}
		if (s.length() > 2) {
			cnt[s.back() - '0']--;
			bool can = true;
			for (int i = 0; i < w; i++) {
				can = can && cnt[i] == a[n + 1][i];
			}
			if (can) {
				string ns = num[n + 1] + s.substr(2, s.length() - 3);
				ans[ns] = ans[s] + 1;
				q.push(ns);
			} else {
				string ns = s.substr(0, s.length() - 1);
				if (!ans.count(ns)) {
					ans[ns] = ans[s] + 1;
					q.push(ns);
				}
			}
			cnt[s.back() - '0']++;
		}
		for (int i = 0; i < w; i++) {
			if (cnt[i] < 3) {
				cnt[i]++;
				bool can = true;
				for (int j = 0; j < w; j++) {
					can = can && cnt[j] == a[n + 1][j];
				}
				if (can) {
					string ns = num[n + 1] + s.substr(2) + to_string(i);
					ans[ns] = ans[s] + 1;
					q.push(ns);
				} else {
					string ns = s + to_string(i);
					if (!ans.count(ns)) {
						ans[ns] = ans[s] + 1;
						q.push(ns);
					}
				}
				cnt[i]--;
			}
		}
	}
	printf("Case #%d: %d\n", t, ans[num[e]]);
}

int main() {
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		solve(i);
	}
	return 0;
}
