#include<bits/stdc++.h>
using namespace std;

int n, ans;
pair<int, int> a[500005];
unordered_set<int> us, visited;
vector<int> node;
unordered_map<int, vector<int>> edge;

int n_cnt, e_cnt;

void dfs(int p) {
    // cout << p << endl;
    n_cnt++;
    e_cnt += edge[p].size();
    visited.insert(p);

    for (auto x: edge[p]) {
        if (!visited.count(x)) {
            dfs(x);
        }
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x, r;
        scanf("%d %d", &x, &r);
        a[i] = {x - r, x + r};
        us.insert(x - r);
        us.insert(x + r);
        edge[x - r].push_back(x + r);
        edge[x + r].push_back(x - r);
    }

    for (auto x: us) {
        node.push_back(x);
    }

    sort(node.begin(), node.end());
    int m = node.size();

    for (int i = 0; i < m; i++) {
        if (!visited.count(node[i])) {
            n_cnt = 0;
            e_cnt = 0;
            dfs(node[i]);

            // printf("%d %d %d\n", node[i], n_cnt, e_cnt);
            ans += min(n_cnt, e_cnt / 2);
        }
    }

    printf("%d\n", ans);

    return 0;
}