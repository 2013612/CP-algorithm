#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

long long N, a[100006], ans;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + N);
	long long l = 0;
	long long r = 0;
	for (int i = 0; i < N / 2; i++) {
		l += a[i];
	}
	for (int i = 0; i < N / 2; i++) {
		r += a[N - 1 - i];
	}
	if (N % 2 == 1) {
		r += a[N/2];
	}
	ans = l*l + r*r;
	printf("%lld\n", ans);
	return 0;
}
