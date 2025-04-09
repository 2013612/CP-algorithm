#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;

int n, m, a[100006], ans;

void solve() {
	scanf("%d %d", &n, &m);
	string s[10];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	vector<pii> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'R') {
				v.push_back({i, j});
			}
		}
	}
	for (auto [x1, y1] : v) {
		bool can = true;
		for (auto [x2, y2] : v) {
			if (x2 - x1 < 0 || y2 - y1 < 0) {
				can = false;
				break;
			}
		}
		if (can) {
			printf("YES\n");
			return;
		}
	}
	printf("NO\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}