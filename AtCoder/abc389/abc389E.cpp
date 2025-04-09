#include<iostream>
#include<algorithm>
using namespace std;

int n;
long long m, a[200006];

int main() {
	scanf("%d %lld", &n, &m);
	
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	
	sort(a, a + n);
	
	long long l = 0;
	long long r = m + 1;
	long long ans = 0;
	
	while (l + 1 < r) {
		long long mid = (l + r) / 2;
		
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			long long k = (mid / a[i] + 1) / 2;
			
			long double temp = 1;
			temp = temp * k * k * a[i];
			
			if (temp > m) {
				sum = m + 1;
				break;
			}
			
			if (sum > m - k * k * a[i]) {
				sum = m + 1;
				break;
			}
			sum += k * k * a[i];
		}
		
		if (sum <= m) {
			l = mid;
		} else {
			r = mid;
		}
	}
	
	long long t = m;
	
	for (int i = 0; i < n; i++) {
		long long k = (l / a[i] + 1) / 2;
		t -= k * k * a[i];
		
		ans += k;
	}
	
	for (int i = 0; i < n; i++) {
		long long k = (l / a[i] + 1) / 2 + 1;
		
		if ((2 * k - 1) * a[i] <= t) {
			ans++;
			t -= (2 * k - 1) * a[i];
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}