#include<bits/stdc++.h>
using namespace std;

int n, ans, a[500005];


int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += a[k];
            }

            int t = 1;
            for (int k = i; k <= j; k++) {
                if (sum % a[k] == 0) {
                    t = 0;
                    break;
                }
            }

            ans += t;
        }
    }

    printf("%d\n", ans);

    return 0;
}