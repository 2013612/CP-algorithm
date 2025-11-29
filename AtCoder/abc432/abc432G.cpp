#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

using mint = modint998244353;

int n, m, ans;
mint a[500005], b[500005];


int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    printf("%d\n", ans);

    return 0;
}