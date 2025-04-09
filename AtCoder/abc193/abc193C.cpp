#include<iostream>
using namespace std;

long long N, ans;
bool a[100006];
int main() {
	scanf("%lld", &N);
	a[0] = a[1] = true;
	for (long long i = 2; i * i <= N; i++) {
		if (!a[i]) {
			a[i] = true;
			for (long long j = i * i; j <= N; j *= i) {
				if (j <= 100000) {
					a[j] = true;
				}
				ans++;
			}
		}
	}
	printf("%lld\n", N - ans);
	return 0;
}
