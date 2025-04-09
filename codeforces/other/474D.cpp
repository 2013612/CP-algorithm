#include<iostream>

int t, k, max_b, a[100006], b[100006], s[100006], dp[100006];
int main(){
	scanf("%d %d", &t, &k);
	for (int i = 1; i <= t; i++){
		scanf("%d %d", &a[i], &b[i]);
		if (b[i] > max_b) max_b = b[i];
	}
	for (int i = 0; i <= max_b; i++){
		if (i < k){
			dp[i] = 1;
		} else {
			dp[i] = (dp[i-1] + dp[i-k]) % (1000000000 + 7);
		}
	}
	for (int i = 1; i <= max_b; i++){
		s[i] = (s[i-1] + dp[i]) % (1000000000 + 7);
	}
	for (int i = 1; i <= t; i++){
		printf("%d\n", (s[b[i]] - s[a[i] - 1] + 1000000007) % 1000000007);
	}
	return 0;
}
