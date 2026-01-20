#include<bits/stdc++.h>
using namespace std;

int n, ans, a[500005];


int main() {
    scanf("%d", &n);

    ans = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (i > ans) {
            break;
        }

        ans = max(ans, i + a[i] - 1);
    }

    printf("%d\n", min(ans, n));

    return 0;
}