#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;

int n, a[200006], ans, b[100006];
pii c[200006], d[200006];

void solve() {
	string s;
	cin >> s;
	int l = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			l = i;
			break;
		}
	}
	s = s.substr(l);
	while (!s.empty() && s.back() == '0') {
		s.pop_back();
	}
	int num0 = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			num0++;
		}
	}
	ans = num0;
	l = 0;
	int r = s.size() - num0;
	while (l < r) {
		//printf("%d %d\n", l, r);
		int mid = (l + r) / 2;
		int k = 1e9;
		int cnt[2] = {0, 0};
		int ind = -1;
		for (int i = 0; i < s.size(); i++) {
			cnt[s[i] - '0']++;
			if (cnt[1] > mid) {
				ind = i;
				break;
			}
		}
		int t = s.size() - 1;
		bool can = false;
		for (int i = ind; i >= 0; i--) {
			cnt[s[i] - '0']--;
			while (cnt[1] < mid && t > i) {
				cnt[s[t] - '0']++;
				t--;
			}
			k = min(k, num0 - cnt[0]);
			if (k <= mid) {
				can = true;
				break;
			}
		}
		if (can) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	ans = min(ans, l);
	l = 0, r = num0;
	while (l < r) {
		//printf("%d %d\n", l, r);
		int mid = (l + r) / 2;
		int k = 1e9;
		int cnt[2] = {0, 0};
		int ind = -1;
		for (int i = 0; i < s.size(); i++) {
			cnt[s[i] - '0']++;
			if (num0 - cnt[0] < mid) {
				ind = i;
				break;
			}
		}
		int t = s.size() - 1;
		bool can = false;
		for (int i = ind; i >= 0; i--) {
			cnt[s[i] - '0']--;
			while (num0 - cnt[0] > mid && t > i) {
				cnt[s[t] - '0']++;
				t--;
			}
			//printf("!%d %d %d %d\n", i, t, cnt[0], cnt[1]);
//			if (num0 - cnt[0] > mid) {
//				break;
//			}
			
			k = min(k, cnt[1]);
			if (k <= mid) {
				can = true;
				break;
			}
		}
		if (can) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	ans = min(ans, l);
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}