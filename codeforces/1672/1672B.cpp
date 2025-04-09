#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ans;

void solve() {
	string s;
	cin >> s;
	n = s.length();
	ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A') {
			ans++;
		} else {
			ans--;
		}
		if (ans < 0) {
			printf("NO\n");
			return;
		}
	}
	if (s.back() != 'B') {
		printf("NO\n");
	} else {
		printf("YES\n");
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
