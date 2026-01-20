#include<bits/stdc++.h>
using namespace std;

int n, q, ans, a[500005];
set<pair<int, int>> s;

int main() {
    scanf("%d %d", &n, &q);

    ans = n;
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);

        auto it = s.upper_bound({l, -1});
        if (it != s.begin()) {
            it--;
        }

        auto [x, y] = *it;
        // printf("!!! %d %d\n", x, y);
        while (it != s.end() && (*it).second < l) {
            // printf("!!! hi2\n");
            it++;
        }

        auto it2 = it;
        while (it2 != s.end() && (*it2).first <= r) {
            auto [u, v] = *it2;
            l = min(l, u);
            r = max(r, v);

            ans += v - u + 1;
            it2++;
            // printf("!! %d %d %d\n", u, v, ans);
        }
        
        s.erase(it, it2);
        s.insert({l, r});

        // printf("!!! %d %d\n", l, r);
        ans -= r - l + 1;
        printf("%d\n", ans);
    }

    return 0;
}