#include<iostream>
#include<vector>
using namespace std;

int n, m, l, s, t;
bool ans[200005];
vector<pair<int, int>> edge[200005];

void dfs(int cur, int len, int sum) {
  if (len == l) {
    if (sum >= s) {
      ans[cur] = true;
    }
    
    return;
  }
  
  for (auto [x, y]: edge[cur]) {
    if (sum + y <= t) {
      dfs(x, len + 1, sum + y);
    }
  }
}

int main() {
  scanf("%d %d %d %d %d", &n, &m, &l, &s, &t);
  
  for (int i = 0; i < m; i++) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    edge[u].push_back({v, c});
  }
  
  dfs(1, 0, 0);
  
  for (int i = 1; i <= n; i++) {
    if (ans[i]) {
      printf("%d ", i);
    }
  }
  printf("\n");
  
  return 0;
}