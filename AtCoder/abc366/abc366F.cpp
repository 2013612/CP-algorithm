#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;

int n, k;
long long dp[200006][13];
pii a[200006];

bool f(pii a, pii b) {
	return b.second * (a.first - 1) < a.second * (b.first - 1);
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
	}
	sort(a, a + n, f);
	dp[0][0] = 1;
	
	for (int i = 0; i < n; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= k; j++) {
			dp[i + 1][j] = max(dp[i][j], a[i].first * dp[i][j - 1] + a[i].second);
		}
	}
	
	printf("%lld\n", dp[n][k]);
	return 0;
}