#include<bits/stdc++.h>
#include<atcoder/segtree>
using namespace std;
using namespace atcoder;

long long op(long long a, long long b) {
    return a + b;
}

long long e() {
    return 0;
}

segtree<long long, op, e> seg(5e5 + 10);
segtree<long long, op, e> seg2(5e5 + 10);

int n, q, a[500005], ans;

int main() {
    scanf("%d %d", &n, &q);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        seg.set(a[i], seg.get(a[i]) + a[i]);
        seg2.set(a[i], seg2.get(a[i]) + 1);
    }

    // for (int i = 0; i <= 7; i++) {
    //     printf("%lld ", seg.get(i));
    // }
    // printf("\n");

    // for (int i = 0; i <= 7; i++) {
    //     printf("%lld ", seg2.get(i));
    // }
    // printf("\n");

    for (int i = 0; i < q; i++) {
        int t, x, y;
        scanf("%d %d %d", &t, &x, &y);

        if (t == 1) {
            int p = a[x];
            a[x] = y;
            seg.set(p, seg.get(p) - p);
            seg.set(y, seg.get(y) + y);
            seg2.set(p, seg2.get(p) - 1);
            seg2.set(y, seg2.get(y) + 1);

            // for (int i = 0; i <= 7; i++) {
            //     printf("%lld ", seg.get(i));
            // }
            // printf("\n");

            // for (int i = 0; i <= 7; i++) {
            //     printf("%lld ", seg2.get(i));
            // }
            // printf("\n");
        } else {
            long long ans = 0;

            if (x >= y) {
                ans = 1ll * x * n;
            } else {
                ans += seg.prod(x, y);
                // printf("%lld\n", ans);
                ans += seg2.prod(0, x) * x;
                // printf("%lld\n", ans);
                ans += seg2.prod(y, 5e5 + 5) * y;
            }
            

            printf("%lld\n", ans);
        }
    }

    return 0;
}