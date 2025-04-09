#include<iostream>
using namespace std;

int D, G, p[102], c[102], dp[11][10005], no_q, maxi;
int main() {
	scanf("%d %d", &D, &G);
	for (int i = 1; i <= D; i++) {
		scanf("%d %d", &p[i], &c[i]);
		no_q += p[i];
	}
	for (int i = 1; i <= D; i++) {
		for (int j = 1; j <= no_q; j++){
			maxi = dp[i-1][j];
			for (int k = 1; k <= p[i] && k <= j; k++){
				maxi = max(maxi, dp[i-1][j-k] + k*i*100);
				if (k == p[i]){
					maxi = max(maxi, dp[i-1][j-k] + k*i*100 + c[i]);
				}
			}
			dp[i][j] = maxi;
		}
	}
	for (int i = 1; i <= no_q; i++){
		if (dp[D][i] >= G){
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}
