#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

long long T, N, ans, two[104];
int main() {
	scanf("%lld", &T);
	two[0] = 1;
	for (int i = 1; i <= 61; i++) {
		two[i] = two[i - 1] * 2;
		//printf("!%lld\n", two[i]);
	}
	for (long long i = 0; i < T; i++) {
		scanf("%lld", &N);
		ans = 0;
		for (long long j = 0; j <= 61; j++) {
			if (N & 1) {
				ans += two[j + 1] - 1;
			}
			N = (N >> 1);
			//printf("%d %lld\n", j, ans);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
