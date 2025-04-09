#include<iostream>
#include<vector>
using namespace std;

const int MOD = 998244353;
int N, M, K;
vector<int> brok[5003];
long long dp[5003][5003], prev_sum, next_sum;
int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < M; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		brok[u].push_back(v);
		brok[v].push_back(u);
	}
	dp[1][0] = 1;
	prev_sum = 1;
	for (int i = 1; i <= K; i++) {
		next_sum = 0;
		for (int j = 1; j <= N; j++) {
			dp[j][i] = prev_sum;
			for (auto x:brok[j]) {
				dp[j][i] = (dp[j][i] - dp[x][i - 1] + MOD) % MOD;
			}
			dp[j][i] = (dp[j][i] - dp[j][i - 1] + MOD) % MOD;
			next_sum = (next_sum + dp[j][i]) % MOD;
		}
		prev_sum = next_sum;
	}
	printf("%lld\n", dp[1][K]);
	return 0;
}
