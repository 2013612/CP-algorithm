#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

const int M = 1e9 + 7;

int n, a[1000006];

void solve() {
	scanf("%d", &n);
	long long ans = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);

		ans += 1ll * (n - i) * (i + 1);
	}

	unordered_map<int, long long> um;
	um[0] = 1;

	int cur = 0;

	for (int i = 0; i < n; i++) {
		cur ^= a[i];

		ans -= 1ll * um[cur] * (um[cur] + 1) / 2;

		um[cur]++;
	}

	printf("%lld\n", ans);
}

int main() {
	freopen("narrowing_down_input.txt", "r", stdin);
	freopen("narrowing_down_output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}