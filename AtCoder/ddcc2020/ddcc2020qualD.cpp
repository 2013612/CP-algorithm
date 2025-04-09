#include<iostream>
using namespace std;

int m;
long long ans, k;
int main() {
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		long long c, d;
		scanf("%lld %lld", &d, &c);
		ans += c;
		k += d * c;
	}
	printf("%lld\n", ans + (k - 1) / 9 - 1);
	return 0;
}
