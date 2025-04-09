#include<iostream>
#include<algorithm>
using namespace std;

int m, n;
long long k, a[200006], b[200006], pre[200006];

int main() {
	scanf("%d %d %lld", &n, &m, &k);
	
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		b[i] = a[i];
		k -= a[i];
	}
	
	if (n == m) {
		for (int i = 0; i < n; i++) {
			printf("0 ");
		}
		printf("\n");
		
		return 0;
	}
	
	sort(b, b + n);
	
	for (int i = 0; i < n; i++) {
		pre[i + 1] = pre[i] + b[i];
	}
	
	for (int i = 0; i < n; i++) {
		long long l = -1;
		long long r = k + 1;
		
		int ind = lower_bound(b, b + n, a[i]) - b;

		while (l + 1 < r) {
			long long mid = (l + r) / 2;
			
			int t = upper_bound(b, b + n, a[i] + mid) - b;
			long long sum = pre[t] - pre[n - m];
			if (ind >= n - m) {
				sum = pre[t] - pre[n - m - 1] - a[i];
			}
			long long need = (a[i] + mid + 1) * (t - (n - m)) - sum;
			
			if (sum < 0 || need + mid <= k) {
				l = mid;
			} else {
				r = mid;
			}
		}
		
		if (r > k) {
			printf("-1 ");
		} else {
			printf("%lld ", r);
		}
	}
	
	printf("\n");
	
	return 0;
}