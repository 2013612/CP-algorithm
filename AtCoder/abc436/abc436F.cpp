#include<iostream>
#include<atcoder/segtree>
using namespace std;
using namespace atcoder;

int n, b[500005], rev[500005];
long long ans;

int f(int a, int b) {
  return a + b;
}

int e() {
  return 0;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    b[i]--;
    rev[b[i]] = i;
  }
  
  segtree<int, f, e> s(n);
  for (int i = 0; i < n; i++) {
    ans += 1ll * (s.prod(0, rev[i]) + 1) * (s.prod(rev[i] + 1, n) + 1);
    s.set(rev[i], 1); 
  }
  
  printf("%lld\n", ans);
}
