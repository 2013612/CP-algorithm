#include <iostream>

using namespace std;

int H, W, a[2004][2004], h_sum[2004], w_sum[2004];
int main()
{
    scanf("%d %d", &H, &W);
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            scanf("%d", &a[i][j]);
            h_sum[i] += a[i][j];
        }
    }
    for (int i = 1; i <= W; i++) {
        for (int j = 1; j <= H; j++) {
            w_sum[i] += a[j][i];
        }
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            printf("%d ", h_sum[i] + w_sum[j] - a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

