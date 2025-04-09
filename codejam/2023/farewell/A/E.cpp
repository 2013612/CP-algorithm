#include<iostream>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int start = 0;
    while (start < n && s[start] == s.back()) {
        start++;
    }
    if (start == n) {
        printf("%d\n", (n + 1) / 2);
        return;
    }
    s = s + s;
    int cnt = 1;
    int ans = 0;
    for (int i = start + 1; i < start + n; i++) {
        if (s[i] == s[i - 1]) {
            cnt++;
        } else {
            ans += cnt / 2;
            cnt = 1;
        }
    }
    printf("%d\n", ans + cnt / 2);
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