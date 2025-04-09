#include<iostream>
using namespace std;

int n;
string s;

void solve() {
	scanf("%d", &n);
	cin >> s;
	long long ans = 0;
	int cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] != s[i + 1]) {
			cnt++;
		}
	}
	
	ans += 1ll * cnt * (2 * n - cnt - 3) / 2;
	
	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}