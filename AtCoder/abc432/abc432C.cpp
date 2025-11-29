#include<bits/stdc++.h>
using namespace std;

int n, x, y, a[300005];
long long ans;

int main() {
    scanf("%d %d %d", &n, &x, &y);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);

    long long c = a[0];

    int g = gcd(x, y);
    int s = x / g;
    int t = y / g;
    int d = t - s;
    ans = c;

    for (int i = 1; i < n; i++) {
        if ((a[i] - a[i - 1]) % d) {
            ans = -1;
            break;
        }

        c -= 1ll * (a[i] - a[i - 1]) / d * s;

        if (c < 0) {
            ans = -1;
            break;
        }

        ans += c;
    }

    printf("%lld\n", ans);

    return 0;
}