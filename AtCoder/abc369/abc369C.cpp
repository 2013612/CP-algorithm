#include<iostream>
using namespace std;

int n, a[200006];
long long ans;
int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	a[n] = -2e9;
	
	int len = 2;
	for (int i = 2; i <= n; i++) {
		if (a[i] - a[i - 1] == a[i - 1] - a[i - 2]) {
			len++;
		} else {
			ans += 1ll * len * (len - 1) / 2;
			len = 2;
		}
	}
	
	printf("%lld\n", ans + n);
	return 0;
}