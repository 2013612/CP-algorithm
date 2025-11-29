#include<bits/stdc++.h>
using namespace std;

int n, m, ans, a[500005], cnt[103];


int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        int p, q;
        scanf("%d %d", &p, &q);
        a[p] += q;
        cnt[p]++;
    }

    for (int i = 1; i <= m; i++) {
        printf("%.9lf\n", (double)a[i] / cnt[i]);
    }

    return 0;
}