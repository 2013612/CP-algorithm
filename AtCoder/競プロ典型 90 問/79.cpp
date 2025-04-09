#include <iostream>

using namespace std;

int H, W, a[103][103], b[103][103];
long long ans;

int main()
{
    scanf("%d %d", &H, &W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    for (int i = 0; i < H - 1; i++) {
        for (int j = 0; j < W - 1; j++) {
            long long temp = b[i][j] - a[i][j];
            ans += abs(temp);
            a[i][j] += temp;
            a[i + 1][j] += temp;
            a[i][j + 1] += temp;
            a[i + 1][j + 1] += temp;
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (a[i][j] != b[i][j]) {
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    printf("%lld\n", ans);
    return 0;
}

