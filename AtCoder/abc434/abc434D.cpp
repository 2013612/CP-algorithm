#include<bits/stdc++.h>
using namespace std;

int n, ans, a[2004][2004], b[2004][2004], u[200005], d[200005], l[200005], r[200005], sum;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &u[i], &d[i], &l[i], &r[i]);
        a[u[i]][l[i]]++;
        a[d[i] + 1][l[i]]--;
        a[u[i]][r[i] + 1]--;
        a[d[i] + 1][r[i] + 1]++;
    }

    // for (int i = 0; i <= 10; i++) {
    //     for (int j = 0; j <= 10; j++) {
    //         printf("%d ", a[i][j]);
    //     }
    //     printf("\n");
    // }

    // printf("\n");

    for (int i = 0; i <= 2000; i++) {
        for (int j = 1; j <= 2000; j++) {
            a[i][j] += a[i][j - 1];
        }
    }

    for (int j = 0; j <= 2000; j++) {
        for (int i = 1; i <= 2000; i++) {
            a[i][j] += a[i - 1][j];
        }
    }

    // for (int i = 0; i <= 10; i++) {
    //     for (int j = 0; j <= 10; j++) {
    //         printf("%d ", a[i][j]);
    //     }
    //     printf("\n");
    // }

    for (int i = 0; i <= 2000; i++) {
        for (int j = 0; j <= 2000; j++) {
            sum += a[i][j] > 0;
            if (a[i][j] > 1) {
                a[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= 2000; i++) {
        for (int j = 1; j <= 2000; j++) {
            b[i][j] = a[i][j] + b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        int temp = b[d[i]][r[i]] - b[u[i] - 1][r[i]] - b[d[i]][l[i] - 1] + b[u[i] - 1][l[i] - 1];
        printf("%d\n", 2000 * 2000 - (sum - temp));
    }

    return 0;
}