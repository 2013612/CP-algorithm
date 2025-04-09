#include<iostream>
using namespace std;

int N, W, v[103], w[103], dp[103][10005];

int main() {
    scanf("%d %d", &N, &W);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &v[i], &w[i]);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= W; j++) {
            if (j >= w[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + v[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= W; i++) {
        ans = max(ans, dp[N][i]);
    }
    printf("%d\n", ans);
    return 0;
}
