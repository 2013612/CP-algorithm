#include<iostream>
using namespace std;

int h, w, k, a[200006], b[200006];
long long ans;
int main() {
	scanf("%d %d %d", &h, &w, &k);
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < h; i++) {
		scanf("%d", &a[i]);
		sum1 += a[i];
		sum1 %= k;
	}
	for (int i = 0; i < w; i++) {
		scanf("%d", &b[i]);
		sum2 += b[i];
		sum2 %= k;
	}
	if (sum1 != sum2) {
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < h; i++) {
		long long t = 1ll * (k - 1) * (w - 1) % k;
		t = a[i] - t;
		t = (t + k) % k;
		ans += 1ll * (k - 1) * (w - 1) + t;
	}
	printf("%lld\n", ans);
	return 0;
}
