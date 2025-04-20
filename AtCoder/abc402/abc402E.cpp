#include<bits/stdc++.h>
using namespace std;

int n, x, s[20], c[20], p[20], ans;
long double dp[256][5010];

long double f(int bit, int yen) {
	if (dp[bit][yen] >= 0) {
		return dp[bit][yen];
	}
	
	long double temp = 0;
	
	for (int i = 0; i < n; i++) {
		if ((bit & (1 << i)) && c[i] <= yen) {
			long double suc = s[i];
			suc += f(bit - (1 << i), yen - c[i]);
			suc = suc * p[i] / 100;
			long double fail = f(bit, yen - c[i]) / 100 * (100 - p[i]);
			
			long double tt = 1;
			tt = tt * s[i] * p[i] / 100;
			
//			printf("%d %d %d %.9Lf %.9Lf %.9Lf\n", i, bit, yen, tt, f(bit - (1 << i), yen - c[i]), fail);
			
			temp = max(temp, suc + fail);
		}
	}
	
	dp[bit][yen] = temp;
	
//	printf("%d %d %.9Lf\n", bit, yen, temp);
	
	return dp[bit][yen];
}

int main() {
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &s[i], &c[i], &p[i]);
	}
	
	for (int i = 0; i < (1 << 8); i++) {
		for (int j = 0; j < 5005; j++) {
			dp[i][j] = -1e9;
		}
	}
	
	printf("%.9Lf\n", f((1 << n) - 1, x));
	return 0;
}