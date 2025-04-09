#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

template<class T, class U> inline bool chmin(T &x, const U& y) { return y < x ? x = y, 1 : 0; }

int N, M;

vector<ll> dijkstra(vector<vector<pii>> &G, int v) {
    vector<ll> ans(N + 1, 2e9);
    ans[v] = 0;
    auto cmp = [&](int i, int j) { return ans[i] > ans[j]; };
    priority_queue<int, vector<int>, decltype(cmp)> que(cmp);
    vector<bool> flag(N + 1);
    que.push(v);
    while (!que.empty()) {
        auto f = que.top();
        que.pop();
        if (flag[f]) continue;
        flag[f] = true;
        for (auto i : G[f])
            if (chmin(ans[i.first], ans[f] + i.second)) {
                que.push(i.first);
                flag[i.first] = false;
            }
    }
    return ans;
}

vector<vector<pii>> edge(100006, vector<pii>());

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }
    vector<ll> start = dijkstra(edge, 1);
    vector<ll> end = dijkstra(edge, N);
    for (int i = 1; i <= N; i++) {
        printf("%lld\n", start[i] + end[i]);
    }
    return 0;
}

