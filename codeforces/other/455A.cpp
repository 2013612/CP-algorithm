#include<iostream>

int c[100006], a, n, max_a;
long long dp[100006];
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a);
		c[a]++;
		max_a = std::max(a, max_a);
	}
	dp[0] = 0;
	dp[1] = c[1];
	for (int i = 2; i <= max_a; i++){
		dp[i] = std::max(dp[i-1], dp[i-2] + 1ll*c[i]*i);
	}
	printf("%lld\n", dp[max_a]);
	return 0;
}
