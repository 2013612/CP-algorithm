#include<iostream>
using namespace std;
const int M = 998244353;

int a[200006], ra[200006], b[200006], rb[200006], sum[200006];
long long ans;
void solve() {
	int n, s;
	scanf("%d %d", &n, &s);
	ans = 1;
	for (int i = 1; i <= n; i++) {
		a[i] = b[i] = ra[i] = rb[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		ra[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		if (b[i] > 0) {
			rb[b[i]] = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1];
		if (b[ra[i]] == -1) {
			sum[i]++;
		}
	}
	
	for (int i = 1; i < n; i++) {
		if (rb[i] > 0) {
			if (a[rb[i]] - i > s) {
				ans = 0;
			}
			int t = ra[i];
			ra[a[rb[i]]] = t;
			swap(a[t], a[rb[i]]);
		} else {
			if (b[ra[i]] > i) {
				ans = ans * (sum[min(i + s, n)] - sum[i]) % M;
			} else if (b[ra[i]] == -1) {
				ans = ans * (sum[min(i + s, n)] - sum[i] + 1) % M;
			}
		}
	}
	
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