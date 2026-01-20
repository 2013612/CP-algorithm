#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
typedef pair<int, int> pii;

int n, a[500005], x;
long long ans;
vector<pii> v;

pii op(pii a, pii b) {
    if (a.first > b.first) {
        return a;
    } else {
        return b;
    }
}

pii e() {
    return {0, 0};
}

segtree<pii, op, e> seg;

long long solve(int l, int r, int cur) {
    // printf("!!! %d %d %d\n", l, r, cur);

    // if (cur % 10 == 0) {
    //     printf("!!! %d %d %d\n", l, r, cur);
    // }

    if (l + 1 >= r) {
        // printf("!!! %d %d %d\n", l, r, cur);
        return 0ll;
    }
    
    long long t1 = 0, t2 = 0;

    if (cur > l) {
        auto [x1, y1] = seg.prod(l, cur);
        long long le = solve(l, cur, y1);
        t1 = le + cur - y1;
    }

    if (cur + 1 < r) {
        auto [x2, y2] = seg.prod(cur + 1, r);
        long long ri = solve(cur + 1, r, y2);
        t2 = ri + y2 - cur;
    }

    return max(t1, t2);
}

int main() {
    scanf("%d", &n);
    // n = 2e5;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        // a[i] = i + 1;
        v.push_back({a[i], i});

        if (a[i] == n) {
            x = i;
        }
    }

    seg = segtree<pii, op, e>(v);

    ans = solve(0, n, x);

    printf("%lld\n", ans);

    return 0;
}