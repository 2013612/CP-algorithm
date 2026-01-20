#include<bits/stdc++.h>
using namespace std;

int n, ans, a[500005];


int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        ans += i + 1;
    }

    printf("%d\n", ans);

    return 0;
}