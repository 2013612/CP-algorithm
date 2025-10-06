#include<bits/stdc++.h>
using namespace std;

int t, n, ans;

void solve() {
    scanf("%d", &n);

    string s;
    cin >> s;

    int a[2] = {0, 0};

    for (int i = 0; i < s.size(); i++) {
        a[s[i] - '0']++;
    }

    s.push_back('.');
    int cnt = 1;
    int ans = 1e9;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) {
            int cur = s[i - 1] - '0';
            ans = min(ans, (a[cur] - cnt) * 2 + a[1 - cur]);
            cnt = 1;
        } else {
            cnt++;
        }
    }

    printf("%d\n", ans);
}

int main() {
    scanf("%d", &t);
    
    while (t-- > 0) {
        solve();
    }

    return 0;
}