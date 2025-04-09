#include<iostream>
using namespace std;

int dp[103][3], n, a;
int main(){
	scanf("%d", &n);
	dp[0][0] = dp[0][1] = dp[0][2] = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d", &a);
		switch (a){
			case 0: {
				dp[i][0] = dp[i][1] = 1000;
				dp[i][2] = min(min(dp[i-1][0], dp[i-1][1]), dp[i-1][2]) + 1;
				break;
			}
			case 1: {
				dp[i][0] = 1000;
				dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
				dp[i][2] = min(min(dp[i-1][0], dp[i-1][1]), dp[i-1][2]) + 1;
				break;
			}
			case 2: {
				dp[i][1] = 1000;
				dp[i][0] = min(dp[i-1][1], dp[i-1][2]);
				dp[i][2] = min(min(dp[i-1][0], dp[i-1][1]), dp[i-1][2]) + 1;
				break;
			}
			case 3: {
				dp[i][0] = min(dp[i-1][1], dp[i-1][2]);
				dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
				dp[i][2] = min(min(dp[i-1][0], dp[i-1][1]), dp[i-1][2]) + 1;
				break;
			}
		}
	}
	printf("%d\n", min(min(dp[n][0], dp[n][1]), dp[n][2]));
	return 0;
}
