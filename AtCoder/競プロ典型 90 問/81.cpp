#include <iostream>
using namespace std;

int N, K, a[5004][5004], sum[5004][5004], ans;
int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x][y]++;
    }
    for (int i = 1; i <= 5000; i++) {
        for (int j = 1; j <= 5000; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }
    for (int i = 1; i <= 5000 - K; i++) {
        for (int j = 1; j <= 5000 - K; j++) {
            ans = max(ans, sum[i + K][j + K] - sum[i - 1][j + K] - sum[i + K][j - 1] + sum[i - 1][j - 1]);
        }
    }
    printf("%d\n", ans);
    return 0;
}

