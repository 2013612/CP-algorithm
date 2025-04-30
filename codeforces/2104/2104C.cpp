#include<bits/stdc++.h>
using namespace std;

int n, a[300006], ans;

void solve() {
	scanf("%d", &n);
	ans = 0;
	string s;
	cin >> s;
	unordered_set<int> us[2];
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A') {
			us[0].insert(i + 1);
		} else {
			us[1].insert(i + 1);
		}
	}
	
	if ((us[0].count(n) && (us[0].count(1) || us[0].count(n - 1))) || (us[1].count(n) && us[1].size() == 1)) {
		printf("Alice\n");
	} else {
		printf("Bob\n");
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}