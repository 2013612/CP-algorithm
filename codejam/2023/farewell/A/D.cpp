#include<iostream>
using namespace std;

void solve() {
    long long n;
    scanf("%lld", &n);
    long long cnt = 1;
    while (true) {
        if (n <= 26 * cnt * (cnt + 1) / 2) {
            break;
        }
        cnt++;
    }
    n -= 26 * (cnt - 1) * cnt / 2;
    n = (n + cnt - 1) / cnt - 1;
    printf("%c\n", 'A' + n);
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