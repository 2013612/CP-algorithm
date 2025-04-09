#include<iostream>

using namespace std;

int N, R[103], C[103], dp[103][103];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &R[i], &C[i]);
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; i + j < N; j++) {
            dp[j][i + j] = dp[j + 1][i + j] + R[j] * C[j] * C[i + j];
            for (int k = 1; j + k < i + j; k++) {
                dp[j][i + j] = min(dp[j][i + j], dp[j][j + k] + dp[j + k + 1][i + j] + R[j] * C[j + k] * C[i + j]);
            }
        }
    }
    printf("%d\n", dp[0][N - 1]);
    return 0;
}
