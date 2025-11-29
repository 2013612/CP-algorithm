#include<bits/stdc++.h>
using namespace std;

int n, h, t[500005], l[500005], u[500005];
bool ans;

void solve() {
    scanf("%d %d", &n, &h);
    ans = true;

    int mini = h;
    int maxi = h;

    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &t[i], &l[i], &u[i]);

        mini = max({mini - (t[i] - t[i - 1]), l[i], 0});
        maxi = min(maxi + (t[i] - t[i - 1]), u[i]);

        if (maxi < mini) {
            ans = false;
        }
    }

    if (ans) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}


int main() {
    int t;
    scanf("%d", &t);

    while (t-- > 0) {
        solve();
    }

    return 0;
}