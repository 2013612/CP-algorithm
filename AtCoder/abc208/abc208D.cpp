#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
typedef pair<int, int> pii;

int N, M;
long long ans, dp[403][403][403];
vector<pii> edge[1004];
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j][0] = 2e9;
		}
	}
	for (int i = 0; i < M; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge[a].push_back(make_pair(b, c));
		dp[a][b][0] = c;
	}
	for (int k = 1; k <= N; k++) {
		//printf("%d\n", k);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dp[i][j][k] = min(dp[i][j][k - 1], dp[i][k][k - 1] + dp[k][j][k - 1]);
				//printf("%10lld ",dp[i][j][k]);
			}
			//printf("\n");
		}
		//printf("\n");
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (i != j && dp[i][j][k] != 2e9) {
					ans += dp[i][j][k];
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
