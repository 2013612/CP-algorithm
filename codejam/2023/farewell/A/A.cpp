#include<iostream>
#include<unordered_set>
using namespace std;

void solve() {
    int n, a[30];
    for (int i = 0; i < 26; i++) {
        scanf("%d", &a[i]);
    }
    unordered_set<string> us;
    bool can = true;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        string new_s;
        for (char c : s) {
            new_s.push_back(a[c - 'A'] + '0');
        }
        if (us.count(new_s)) {
            can = false;
        }
        us.insert(new_s);
    }
    
    if (can) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
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