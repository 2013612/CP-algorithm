#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[400006];
long long ans;

void solve() {
	scanf("%d", &n);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	
	if (n < 3) {
		printf("-1\n");
		return;
	}
	
	sort(a, a + n);
	
	int mid = a[n / 2];
	
	ans = 1ll * mid * n * 2 - sum + 1;
	
	printf("%lld\n", max(ans, 0ll));
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}