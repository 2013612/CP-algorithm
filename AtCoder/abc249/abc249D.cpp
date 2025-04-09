#include<iostream>
using namespace std;

int n, a[200006];
long long ans;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		a[t]++;
	}
	for (int i = 1; i <= 200000; i++) {
		if (a[i] == 0) {
			continue;
		}
		for (int j = 1; i * j <= 200000; j++) {
			ans += 1ll * a[i] * a[j] * a[i * j];
		}
	}
	printf("%lld\n", ans);
	return 0;
}
