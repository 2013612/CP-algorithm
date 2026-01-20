#include<iostream>
#include<set>
#include<queue>
using namespace std;

const int x[4] = {1, 0, -1, 0};
const int y[4] = {0, 1, 0, -1};

int h, w, dis[1003][1003];
string t[1003];
set<pair<int, int>> s[26];

int main() {
  scanf("%d %d", &h, &w);
  
  for (int i = 1; i <= h; i++) {
    cin >> t[i];
    t[i] = "#" + t[i] + "#";
  }
  
  for (int i = 0; i <= w + 1; i++) {
    t[0].push_back('#');
    t[h + 1].push_back('#');
  }
  
  for (int i = 0; i <= h + 1; i++) {
    for (int j = 0; j <= w + 1; j++) {
      if (t[i][j] == '#') {
        dis[i][j] = 1e9;
      } else {
        dis[i][j] = -1;
        
        if (t[i][j] != '.') {
          s[t[i][j] - 'a'].insert({i, j});
        }
      }
    }
  }
  
  dis[1][1] = 0;
  queue<pair<int, int>> q;
  q.emplace(1, 1);
  
  while (!q.empty()) {
    auto [u, v] = q.front();
    q.pop();
    
    for (int i = 0; i < 4; i++) {
      int new_u = u + x[i];
      int new_v = v + y[i];
      
      if (dis[new_u][new_v] == -1) {
        dis[new_u][new_v] = dis[u][v] + 1;
        q.emplace(new_u, new_v);
      }
    }
    
    if (t[u][v] != '.') {
      for (auto [a, b]: s[t[u][v] - 'a']) {
        if (dis[a][b] == -1) {
          dis[a][b] = dis[u][v] + 1;
          q.emplace(a, b);
        }
      }
      
      s[t[u][v] - 'a'].clear();
    }
  }
  
  printf("%d\n", dis[h][w]);
}
