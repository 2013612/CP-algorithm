#include<iostream>
#include<algorithm>
using namespace std;

const int M = 998244353;

int n, m, a[300005], b[300005], sum[300005];
long long ans;

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    sort(b, b + m);

    for (int i = 0; i < m; i++) {
        sum[i + 1] = (sum[i] + b[i]) % M;
    }

    for (int i = 0; i < n; i++) {
        int ind = lower_bound(b, b + m, a[i]) - b;
        ans += 1ll * a[i] * ind % M - sum[ind] + M;
        ans %= M;
        ans += sum[m] - sum[ind] - 1ll * a[i] * (m - ind) % M + M;
        ans %= M;
    }

    printf("%lld\n", ans);

    return 0;
}