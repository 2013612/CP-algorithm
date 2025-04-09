#include<iostream>
using namespace std;

int ans;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

void solve() {
	int n, k;
	scanf("%d %d", &n, &k);
	
	int g = 0;
	
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		
		if (i == 0) {
			g = a;
		} else {
			g = gcd(g, a);
		}
	}
	
	if (n == 1) {
		ans = k - (k <= g);
	} else if (1ll * (g - 1) * (n - 1) >= k) {
		ans = k + (k - 1) / (g - 1);
	} else {
		ans = k + n - 1;
	}
	
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