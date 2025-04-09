#include<iostream>
#include<set>
#include<atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int N, M;
set<pair<int, int>> us;
mint dp[403][403];
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		us.insert({a, b});
	}
	for (int i = 1; i <= 2 * N - 1; i++) {
		if (us.count({i, i + 1}) == 1) {
			dp[i][i + 1] = 1;
		}
	}
	for (int i = 3; i <= 2 * N; i++) {
		for (int j = 1; i + j <= 2 * N; j++) {
			if (us.count({j + i - 1, j + i}) == 1) {
				dp[j][j + i] += dp[j][j + i - 2];
			}
			if (us.count({j, j + i}) == 1) {
				dp[j][j + i] += dp[j + 1][j + i - 1];
			}
			if (us.count({j, j + 1}) == 1) {
				dp[j][j + i] += dp[j + 2][j + i];
			}
		}
	}
	for (int i = 1; i <= 2 * N; i++) {
		for (int j = 1; j <= 2 * N; j++) {
			printf("%d ", dp[i][j].val());
		}
		printf("\n");
	}
	printf("%d\n", dp[1][2 * N].val());
	return 0;
}
