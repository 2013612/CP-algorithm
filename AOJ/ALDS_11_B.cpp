#include<iostream>
#include<vector>
using namespace std;

int N, ans[103][2], t;
vector<int> a[103];
bool visited[103];

void dfs(int node) {
    ans[node][0] = t;
    t++;
    visited[node] = true;
    for (auto x:a[node]) {
        if (!visited[x]) {
            dfs(x);
        }
    }
    ans[node][1] = t;
    t++;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int u, k;
        scanf("%d %d", &u, &k);
        for (int j = 0; j < k; j++) {
            int temp;
            scanf("%d", &temp);
            a[u].push_back(temp);
        }
    }
    t = 1;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    for (int i = 1; i <= N; i++) {
        printf("%d %d %d\n", i, ans[i][0], ans[i][1]);
    }
    return 0;
}
