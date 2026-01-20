#include<iostream>
#include<set>
using namespace std;

int n, m;
set<pair<int, int>> s;

bool has(int r, int c) {
  if (s.count({r, c})) {
    return true;
  }
  
  if (s.count({r + 1, c})) {
    return true;
  }
  
  if (s.count({r, c + 1})) {
    return true;
  }
  
  if (s.count({r + 1, c + 1})) {
    return true;
  }
  
  return false;
}

int main() {
  scanf("%d %d", &n, &m);
  
  for (int i = 0; i < m; i++) {
    int r, c;
    scanf("%d %d", &r, &c);
    
    if (!has(r, c)) {
      s.insert({r, c});
      s.insert({r + 1, c});
      s.insert({r, c + 1});
      s.insert({r + 1, c + 1});
    }
  }
  
  printf("%d\n", s.size() / 4);
}
