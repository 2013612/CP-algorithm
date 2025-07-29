#include<iostream>
using namespace std;

int n;
long long ans, a[300005], b[300005];

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		b[i + 1] = b[i] + a[i];
	}
	
	for (int i = n - 1; i >= 0; i--) {
		ans += a[i] * b[i];
	}
	
	printf("%lld\n", ans);
	
	return 0;
}