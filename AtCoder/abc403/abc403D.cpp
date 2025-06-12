#include<iostream>
using namespace std;

int n, d, a[200005], b[1000006], ans;

int main() {
	scanf("%d %d", &n, &d);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[a[i]]++;
	}
	
	if (d == 0) {
		for (int i = 0; i <= 1e6; i++) {
			if (b[i]) {
				ans += b[i] - 1;
			}
		}
	} else {
		for (int i = 0; i < d; i++) {
			int dp[2] = {0, 0};
			
			for (int j = 0; (j + 1) * d + i <= 1e6; j++) {
				int t = min(dp[0] + b[j * d + i], dp[1] + b[(j + 1) * d + i]);
				dp[0] = dp[1];
				dp[1] = t;
			}
			ans += dp[1];
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}