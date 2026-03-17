#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int n, a[200005];
vector<int> g[200005];
bool ans[200005], v[200005];
unordered_map<int, int> um;

void dfs(int cur, bool pc) {
    bool c = pc || um[a[cur]] > 0;
    if (c) {
        ans[cur] = true;
    }

    v[cur] = true;
    um[a[cur]]++;

    for (auto x: g[cur]) {
        if (!v[x]) {
            dfs(x, c);
        }
    }

    um[a[cur]]--;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, false);

    for (int i = 0; i < n; i++) {
        if (ans[i]) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}