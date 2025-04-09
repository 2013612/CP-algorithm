#include<iostream>
using namespace std;

int n, x[100006], h[100006], dp[100006][3];

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d %d", &x[i], &h[i]);
	}
	dp[0][0] = dp[0][1] = dp[0][2] = 0;
	x[0] = -1e9;
	x[n+1] = 2e9 + 2;
	for (int i = 1; i <=n; i++){
		if (x[i] - h[i] <= x[i-1]){
			dp[i][0] = -1;
		} else if (x[i] - h[i] <= x[i-1] + h[i-1]){
			dp[i][0] = max(dp[i-1][0], dp[i-1][2]) + 1;
		} else {
			dp[i][0] = max(max(dp[i-1][0], dp[i-1][1]), dp[i-1][2]) + 1;
		}
		if (x[i] + h[i] >= x[i+1]){
			dp[i][1] = -1;
		} else {
			dp[i][1] = max(max(dp[i-1][0], dp[i-1][1]), dp[i-1][2]) + 1;
		}
		dp[i][2] = max(max(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
	}
	printf("%d\n", dp[n][1]);
	return 0;
}
