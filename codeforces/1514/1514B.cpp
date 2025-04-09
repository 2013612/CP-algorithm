#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int M = 1e9 + 7;
int T, N, K;
long long ans;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &K);
		ans = 1;
		for (int j = 0; j < K; j++) {
			ans = (ans * N) % M;
		}
		printf("%lld\n", ans);
	}
	
}
