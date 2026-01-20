#include<iostream>
using namespace std;

int h, w, n, a[10][10], ans[3];

int main() {
    scanf("%d %d %d", &h, &w, &n);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        int b;
        scanf("%d", &b);

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (a[i][j] == b) {
                    a[i][j] = 0;
                    ans[i]++;
                }
            }
        }
    }

    printf("%d\n", max(max(ans[0], ans[1]), ans[2]));
    return 0;
}