#include<iostream>
using namespace std;

long long N, C[303], dp[1004][1004];

int main()
{
    while (true) {
    	scanf("%lld", &N);
    	if (N == 0) {
    		break;
		}
	    for (int i = 0; i < N; i++) {
	        scanf("%lld", &C[i]);
	    }
	    for (int i = 0; i < N; i++) {
	    	for (int j = 0; j < N; j++) {
	    		dp[i][j] = 0;
			}
		}
	    for (int i = 1; i < N; i++) {
	        for (int j = 0; i + j < N; j++) {
	            for (int k = 1; k - 1 <= i; k += 2) {
	                if (abs(C[j] - C[j + k]) <= 1 && dp[j + 1][j + k - 1] == k - 1) {
	                    dp[j][i + j] = max(dp[j][i + j], dp[j + 1][j + k - 1] + dp[j + k + 1][i + j] + 2);
	                } else {
	                	dp[j][i + j] = max(dp[j][i + j], dp[j + 1][j + k - 1] + dp[j + k + 1][i + j]);
					}
	            }
	        }
	    }
	    long long ans = dp[0][N - 1];
	    printf("%lld\n", ans);
	}
    return 0;
}

