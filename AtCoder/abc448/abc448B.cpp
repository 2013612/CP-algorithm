#include<iostream>
using namespace std;

int n, m, c[1003], ans;
int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d", &c[i]);
    }

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;

        int k = min(c[a], b);
        ans += k;
        c[a] -= k;
    }

    printf("%d\n", ans);

    return 0;
}