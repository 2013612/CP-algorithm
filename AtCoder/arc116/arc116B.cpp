#include<iostream>
#include<algorithm>
using namespace std;

const int M = 998244353;
long long N, a[200006];
long long ans;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		ans = (ans + (a[i] * a[i]) % M) % M;
	}
	sort(a, a + N);
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		long long temp = a[i] * sum % M;
		ans = (ans + a[i] * sum) % M;
		sum = (sum * 2 + a[i]) % M;
	}
	printf("%lld\n", ans);
	return 0;
}
