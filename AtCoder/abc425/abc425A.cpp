#include<iostream>
using namespace std;

int n;

int main() {
    scanf("%d", &n);

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        ans += i * i * i * (i & 1 ? -1 : 1);
    }

    printf("%d\n", ans);

    return 0;
}