#include<iostream>
#include<algorithm>
using namespace std;

int N, M, a[103], dp[103][100006];

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= M; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + M + 1);
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == 1) {
                dp[i][j] = j;
            } else {
                if (j >= a[i]) {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - a[i]] + 1);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    printf("%d\n", dp[M][N]);
    return 0;
}
