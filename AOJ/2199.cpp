#include<iostream>

using namespace std;

int N, M, C[20], dp[20005][300];

int main()
{
    while (true) {
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) {
            break;
        }
        for (int i = 0; i < M; i++) {
            scanf("%d", &C[i]);
        }
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j < 256; j++) {
                dp[i][j] = 1e9;
            }
        }
        dp[0][128] = 0;
        for (int i = 1; i <= N; i++) {
            int x;
            scanf("%d", &x);
            for (int j = 0; j < 256; j++) {
                for (int k = 0; k < M; k++) {
                    int temp = j + C[k];
                    temp = min(255, temp);
                    temp = max(0, temp);
                    dp[i][temp] = min(dp[i][temp], dp[i - 1][j] + (temp - x) * (temp - x));
                }
            }
        }
        int ans = 2e9;
        for (int i = 0; i < 256; i++) {
            ans = min(ans, dp[N][i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
