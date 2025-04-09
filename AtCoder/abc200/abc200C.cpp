#include<iostream>
using namespace std;

long long N, a[203], ans;
int main() {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		a[temp % 200]++;
	}
	for (int i = 0; i < 200; i++) {
		ans += a[i] * (a[i] - 1) / 2;
	}
	printf("%lld\n", ans);
	return 0;
}
