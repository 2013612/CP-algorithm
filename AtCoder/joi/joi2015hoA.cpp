#include<iostream>
using namespace std;

int n, m, p[100006], a[100006], b[100006], c[100006], sum[100006];
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
	}
	for (int i = 1; i < m; i++) {
		sum[min(p[i - 1], p[i])]++;
		sum[max(p[i - 1], p[i])]--;
	}
	for (int i = 1; i < n; i++) {
		sum[i] += sum[i - 1];
	}
	long long ans = 0;
	for (int i = 1; i < n; i++) {
		ans += min(1ll * a[i] * sum[i], 1ll * c[i] + 1ll * b[i] * sum[i]);
	}
	printf("%lld\n", ans);
	return 0;
}
