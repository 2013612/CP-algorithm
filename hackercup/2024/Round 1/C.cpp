#include<iostream>
using namespace std;

const int M = 998244353;

void solve() {
	long long g, w, l;
	scanf("%lld %lld %lld", &w, &g, &l);
	
	int x = (w - g) % M;
	l = l % M;
	
	int ans = (1ll * 2 * x * l + x) % M;

	printf("%d\n", ans);
}

int main() {
	freopen("substantial_losses_input.txt", "r", stdin);
	freopen("substantial_losses_output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}