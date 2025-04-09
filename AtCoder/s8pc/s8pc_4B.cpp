#include<iostream>
using namespace std;

int N, K, a[20];
long long ans = 2e18;
int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < (1 << (N - 1)); i++) {
		int cou = 0;
		long long sum = 0;
		long long prev = a[0];
		for (int j = 0; j < N - 1; j++) {
			if (i & (1 << j)) {
				cou++;
				sum += max(prev - a[j + 1] + 1, 0ll);
				prev = max(prev + 1, 1ll * a[j + 1]);
			} else {
				prev = max(prev, 1ll * a[j + 1]);
			}
		}
		if (cou >= K - 1) {
			ans = min(ans, sum);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
