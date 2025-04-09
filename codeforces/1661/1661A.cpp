#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int t;
int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		int n;
		scanf("%d", &n);
		int a[30], b[30];
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &b[i]);
			int mini = min(a[i], b[i]);
			int maxi = max(a[i], b[i]);
			a[i] = mini;
			b[i] = maxi;
		}
		for (int i = 1; i < n; i++) {
			ans += abs(a[i] - a[i - 1]);
			ans += abs(b[i] - b[i - 1]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
