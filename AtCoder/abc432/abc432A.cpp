#include<bits/stdc++.h>
using namespace std;

int n, a[300005], ans;

int main() {
    n = 3;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n, greater<int>());


    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}