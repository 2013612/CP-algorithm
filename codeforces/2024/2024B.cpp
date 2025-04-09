#include<iostream>
#include<algorithm>
using namespace std;

int n, k, ans, a[200006], sum;

void solve() {
	scanf("%d %d", &n, &k);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	ans = 0;
	sum = 0;
	sort(a, a + n);
	
	for (int i = 0; i < n; i++) {
		long long total = sum + 1ll * a[i] * (n - i);
		if (total >= k) {
			ans = k + i;
			break;
		}
		sum += a[i];
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