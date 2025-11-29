#include<bits/stdc++.h>
using namespace std;

int w, b, ans, a[500005];


int main() {
    scanf("%d %d", &w, &b);

    w *= 1000;

    ans = w / b + 1;

    printf("%d\n", ans);

    return 0;
}