#include<iostream>
using namespace std;

const int M = 998244353;

int N, K, a[1004];
long long ans = 1;
int main() {
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		a[i] = K;
	}
	for (int i = 1; i <= K; i++) {
		char c;
		int k;
		scanf(" %c %d", &c, &k);
		a[k] = 1;
		if (c == 'L') {
			for (int j = 1; j < k; j++) {
				a[j] = max(a[j] - 1, 1);
			}
		} else {
			for (int j = k + 1; j <= N; j++) {
				a[j] = max(a[j] - 1, 1);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		ans = (ans * a[i]) % M;
	}
	printf("%lld\n", ans);
	return 0;
}
