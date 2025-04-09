#include<iostream>
using namespace std;

long long n, x, a[200006], b[200006], ans = 4e18, sum;
int main() {
	scanf("%lld %lld", &n, &x);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &a[i], &b[i]);
		long long temp = sum + a[i] + b[i] * max(x - i, 0ll);
		ans = min(ans, temp);
		sum += a[i] + b[i];
	}
	printf("%lld\n", ans);
	return 0;
}