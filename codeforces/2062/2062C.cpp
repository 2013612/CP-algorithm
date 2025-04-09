#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, q;
long long ans, a[200006];

void solve() {
	scanf("%d", &n);
	
	ans = -1e18;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	
	ans = sum;
	
	for (int i = 0; i < n - 1; i++) {
		sum = 0;
		for (int j = 0; j < n - i - 1; j++) {
			a[j] = a[j + 1] - a[j];
			sum += a[j];
//			printf("%lld ", a[j]);
		}
		
//		printf("\n");
//		printf("%lld\n", ans);
//		
		ans = max(ans, abs(sum));
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