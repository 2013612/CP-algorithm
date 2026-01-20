#include<iostream>
using namespace std;

int n, p[300005], a[300005], s[300005];
long long ans;
bool visited[300005];

int find(int i) {
  if (a[i] == i) {
    return i;
  }
  
  return a[i] = find(a[i]);
}

void merge(int i, int j) {
  int x = find(i);
  int y = find(j);
  
  if (x == y) {
    return;
  }
  
  a[y] = x;
  s[x] += s[y];
  s[y] = 0;
}

int main() {
  scanf("%d", &n);
  
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
    a[i] = i;
    s[i] = 1;
  }
  
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      int t = p[i];
      while (t != i) {
        merge(i, t);
        visited[t] = true;
        t = p[t];
      }
    }
  }
  
  for (int i = 1; i <= n; i++) {
    ans += 1ll * s[i] * (s[i] - 1) / 2;
  }
  
  printf("%lld\n", ans);
}
