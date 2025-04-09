#include<iostream>
using namespace std;

long long N, M, dp[300006][10], ans;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		scanf("%d", &M);
		int a[5];
		a[0] = a[1] = a[2] = a[3] = a[4] = 0;
		for (int j = 0; j < M; j++) {
			int temp1, temp2;
			scanf("%d %d", &temp1, &temp2);
			if (temp1 == 3 && temp2 > a[4]) {
				a[4] = temp2;
			}
			if (temp1 == 2 && temp2 > a[3]) {
				a[3] = temp2;
			}
			if (temp1 == 1) {
				if (temp2 > a[0]) {
					a[2] = a[1];
					a[1] = a[0];
					a[0] = temp2;
				} else if (temp2 > a[1]) {
					a[2] = a[1];
					a[1] = temp2;
				} else if (temp2 > a[2]) {
					a[2] = temp2;
				}
			}
		}
		long long temp1 = max(a[0], max(a[3], a[4]));
		long long temp2 = a[0] + max(a[1], a[3]);
		long long temp3 = a[0] + a[1] + a[2];
		if (i == 1) {
			dp[i][1] = temp1;
			dp[i][2] = temp2;
			dp[i][3] = temp3;
		}
		if (i == 2) {
			dp[i][1] = max(dp[i - 1][1], temp1);
			dp[i][2] = max(dp[i - 1][2], max(dp[i - 1][1] + temp1, temp2));
			dp[i][3] = max(dp[i - 1][3], max(dp[i - 1][2] + temp1, max(dp[i - 1][1] + temp2, temp3)));
			dp[i][4] = max(dp[i - 1][3] + temp1, max(dp[i - 1][2] + temp2, dp[i - 1][1] + temp3));
			dp[i][5] = max(dp[i - 1][3] + temp2, dp[i - 1][2] + temp3);
			dp[i][6] = dp[i - 1][3] + temp3;
		}
		if (i == 3) {
			dp[i][1] = max(dp[i - 1][1], temp1);
			dp[i][2] = max(dp[i - 1][2], max(dp[i - 1][1] + temp1, temp2));
			dp[i][3] = max(dp[i - 1][3], max(dp[i - 1][2] + temp1, max(dp[i - 1][1] + temp2, temp3)));
			dp[i][4] = max(dp[i - 1][4], max(dp[i - 1][3] + temp1, max(dp[i - 1][2] + temp2, dp[i - 1][1] + temp3)));
			dp[i][5] = max(dp[i - 1][5], max(dp[i - 1][4] + temp1, max(dp[i - 1][3] + temp2, dp[i - 1][2] + temp3)));
			dp[i][6] = max(dp[i - 1][6], max(dp[i - 1][5] + temp1, max(dp[i - 1][4] + temp2, dp[i - 1][3] + temp3)));
			dp[i][7] = max(dp[i - 1][6] + temp1, max(dp[i - 1][5] + temp2, dp[i - 1][4] + temp3));
			dp[i][8] = max(dp[i - 1][6] + temp2, dp[i - 1][5] + temp3);
			dp[i][9] = dp[i - 1][6] + temp3;
		}
		if (i >= 4) {
			dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][9] + 2 * temp1, max(dp[i - 1][8] + temp2 + max(a[0], a[3]), dp[i - 1][7] + temp3 + a[0])));
			dp[i][1] = max(dp[i - 1][1], max(dp[i - 1][0] + temp1, max(dp[i - 1][9] + temp2 + max(a[0], a[3]), dp[i - 1][8] + temp3 + a[0])));
			dp[i][2] = max(dp[i - 1][2], max(dp[i - 1][1] + temp1, max(dp[i - 1][0] + temp2, dp[i - 1][9] + temp3 + a[0])));
			dp[i][3] = max(dp[i - 1][3], max(dp[i - 1][2] + temp1, max(dp[i - 1][1] + temp2, dp[i - 1][0] + temp3)));
			dp[i][4] = max(dp[i - 1][4], max(dp[i - 1][3] + temp1, max(dp[i - 1][2] + temp2, dp[i - 1][1] + temp3)));
			dp[i][5] = max(dp[i - 1][5], max(dp[i - 1][4] + temp1, max(dp[i - 1][3] + temp2, dp[i - 1][2] + temp3)));
			dp[i][6] = max(dp[i - 1][6], max(dp[i - 1][5] + temp1, max(dp[i - 1][4] + temp2, dp[i - 1][3] + temp3)));
			dp[i][7] = max(dp[i - 1][7], max(dp[i - 1][6] + temp1, max(dp[i - 1][5] + temp2, dp[i - 1][4] + temp3)));
			dp[i][8] = max(dp[i - 1][8], max(dp[i - 1][7] + temp1, max(dp[i - 1][6] + temp2, dp[i - 1][5] + temp3)));
			dp[i][9] = max(dp[i - 1][9], max(dp[i - 1][8] + temp1, max(dp[i - 1][7] + temp2, dp[i - 1][6] + temp3)));
		}
		
	}
	for (int i = 0; i < 10; i++) {
		ans = max(ans, dp[N][i]);
	}
	printf("%lld\n", ans);
	return 0;
}
