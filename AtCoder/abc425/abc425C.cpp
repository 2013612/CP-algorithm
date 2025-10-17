#include<iostream>
using namespace std;

int n, q, a[400005], cur;
long long b[400005];

int main() {
    scanf("%d %d", &n, &q);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[n + i] = a[i];
        b[i + 1] = b[i] + a[i];
    }

    for (int i = n; i < 2 * n; i++) {
        b[i + 1] = b[i] + a[i - n];
    }

    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);

        if (t == 1) {
            int c;
            scanf("%d", &c);
            cur += c;
            cur %= n;
        } else {
            int l, r;
            scanf("%d %d", &l, &r);

            printf("%lld\n", b[cur + r] - b[cur + l - 1]);
        }
    }

    return 0;
}