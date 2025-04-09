#include<bits/stdc++.h>
using namespace std;

int n, a[200005];
long long ans, dp[200005];

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	dp[1] = a[0];
	
	for (int i = 1; i < n; i++) {
		dp[i + 1] = max(dp[i] + a[i], dp[i - 1]);
	}
	
	printf("%lld\n", dp[n]);
	
	return 0;
}