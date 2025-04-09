#include<iostream>
using namespace std;

long long N, M, a[103][103], ans;
int main() {
	scanf("%lld %lld", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%lld", &a[i][j]);
		}
	}
	for (int i = 0; i < M - 1; i++) {
		for (int j = i + 1; j < M; j++) {
			long long sum = 0;
			for (int k = 0; k < N; k++) {
				sum += max(a[k][i], a[k][j]);
			}
			ans = max(ans, sum);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
