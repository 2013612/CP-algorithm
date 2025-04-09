#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void solve() {
    int n, a[100005];
    scanf("%d", &n);
    vector<int> ans;
    unordered_set<int> us;
    for (int i = 0 ; i < n; i++) {
        scanf("%d", &a[i]);
    }
    ans.push_back(a[0]);
    us.insert(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            continue;
        }
        if (us.count(a[i])) {
            printf("IMPOSSIBLE\n");
            return;
        } else {
            ans.push_back(a[i]);
            us.insert(a[i]);
        }
    }
    for (int v : ans) {
        printf("%d%c", v, v == ans.back() ? '\n' : ' ');
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