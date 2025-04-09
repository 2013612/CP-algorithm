#include<iostream>
#include<algorithm>
using namespace std;

int n, ans = 1e9;
long long x, y, a[200006];

int main() {
	scanf("%d %lld %lld", &n, &x, &y);
	ans = n;
	
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a, a + n, greater<long long>());
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (sum > x) {
			ans = min(ans, i + 1);
			break;
		}
	}
	
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a, a + n, greater<long long>());
	sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (sum > y) {
			ans = min(ans, i + 1);
			break;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}