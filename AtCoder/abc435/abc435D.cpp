#include<bits/stdc++.h>
using namespace std;

int n, m, q;
bool v[300005];
vector<int> edge[300005];

void dfs(int node) {
    v[node] = true;

    for (auto x: edge[node]) {
        if (!v[x]) {
            dfs(x);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        edge[y].push_back(x);
    }

    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        if (x == 1) {
            if (!v[y]) {
                dfs(y);
            }
        } else {
            if (v[y]) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }

    return 0;
}