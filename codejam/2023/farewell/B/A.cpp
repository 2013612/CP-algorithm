#include<iostream>
using namespace std;

void solve() {
    int n, a[100005];
    long long sum[100005] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    int la, ra, lb, rb;
    scanf("%d %d %d %d", &la, &ra, &lb, &rb);
    long long ans = 0;
    for (int i = la; i <= ra; i++) {
        long long temp = 0;
        if (lb >= i) {
            int k = (lb - i) / 2;
            temp = sum[n] - sum[i + k];
        } else if (rb <= i) {
            int k = (i - rb - 1) / 2;
            temp = sum[min(rb + k, i - 1)];
        } else {
            temp = max(sum[i - 1], sum[n] - sum[i]);
        }
        ans = max(ans, sum[n] - temp);
    }
    printf("%lld\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}