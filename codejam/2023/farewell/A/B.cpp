#include<iostream>
using namespace std;

void solve() {
    int m, r, n, a[100005];
    scanf("%d %d %d", &m, &r, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    int left = 0;
    for (int i = 1; i < n; i++) {
        if (abs(a[i] - left) > r) {
            if (abs(a[i] - a[i - 1]) > 2 * r || abs(a[i - 1] - left) > r) {
                printf("IMPOSSIBLE\n");
                return;
            } else {
                left = a[i - 1] + r;
                ans++;
            }
        }
    }
    
    if (left < m) {
        if (abs(a[n - 1] - left) <= r && abs(a[n - 1] - m) <= r) {
            printf("%d\n", ans + 1);
        } else {
            printf("IMPOSSIBLE\n");
        }
    } else {
        printf("%d\n", ans);
    }
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