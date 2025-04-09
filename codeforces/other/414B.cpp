#include<iostream>

int n, k, dp[2004][2004], ans;
const int m = 1000000007;
int main(){
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= k; j++){
			if (i == 1 || j == 1){
				dp[i][j] = 1;
			} else {
				for (int p = 1; p*p <= i; p++){
					if (i % p == 0){
						if (i/p == p){
							dp[i][j] = (dp[i][j] + dp[p][j-1]) % m;
						} else {
							dp[i][j] = (dp[i][j] + (dp[p][j-1] + dp[i/p][j-1]) % m) % m;
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) ans = (ans + dp[i][k]) % m;
	printf("%d\n", (ans + m) % m);
}
