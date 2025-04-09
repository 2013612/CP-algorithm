#include<iostream>
using namespace std;

int v, e;
long long dp[103][103][103];
int main() {
	scanf("%d %d", &v, &e);
	for (int i = 0; i <= v; i++) {
		for (int j = 0; j <= v; j++) {
			dp[i][j][0] = 1e10;
		}
		dp[i][i][0] = 0;
	}
	for (int i = 0; i < e; i++) {
		int s, t, d;
		scanf("%d %d %d", &s, &t, &d);
		dp[s + 1][t + 1][0] = d;
	}
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			for (int k = 1; k <= v; k++) {
				dp[j][k][i] = min(dp[j][k][i - 1], dp[j][i][i - 1] + dp[i][k][i - 1]);
			}
		}
	}
	bool nc = false;
	for (int i = 1; i <= v; i++) {
		nc = nc || dp[i][i][v] < 0;
	}
	if (nc) {
		printf("NEGATIVE CYCLE\n");
	} else {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (dp[i][j][v] > 5e9) {
					printf("INF");
				} else {
					printf("%d", dp[i][j][v]);
				}
				if (j != v) {
					printf(" ");
				}
			}
			printf("\n");
		}
	}
	return 0;
}
