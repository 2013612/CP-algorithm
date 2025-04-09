#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int N;
vector<int> edge[100006];
bool visited[100006];

pii dfs(int node) {
    visited[node] = true;
    vector<pii> temp;
    for (auto x:edge[node]) {
        if (!visited[x]) {
            temp.push_back(dfs(x));
        }
    }
    sort(temp.begin(), temp.end());
    int temp2 = 0;
    for (auto x:temp) {
        temp2 = max(temp2, x.second);
    }
    if (temp.size() == 0) {
        return make_pair(0, 0);
    } else if (temp.size() == 1) {
        return make_pair(temp[0].first + 1, max(temp2, temp[0].first + 1));
    } else {
        return make_pair(temp[0].first + 1, max(temp2, temp[0].first + temp[1].first + 2));
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    printf("%d\n", dfs(1).second + 1);
    return 0;
}

