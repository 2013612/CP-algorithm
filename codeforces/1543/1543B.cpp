#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
using namespace std;

int T, N;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		long long ans = 0;
		for (int j = 0; j < N; j++) {
			long long temp;
			scanf("%lld", &temp);
			ans += temp;
		}
		printf("%lld\n", (ans % N) * (N - ans % N));
	}
	return 0;
}
