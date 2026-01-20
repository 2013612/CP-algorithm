#include<iostream>
#include<atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppii;

ppii f(ppii a, ppii b) {
  return {{max(a.first.first, b.first.first), min(a.first.second, b.first.second)}, {max(a.second.first, b.second.first), min(a.second.second, b.second.second)}};
}

ppii e() {
  return {{-2e9, 2e9}, {-2e9, 2e9}};
}

int n, q;

int main() {
  scanf("%d %d", &n, &q);
  
  segtree<ppii, f, e> sg(n);
  
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    sg.set(i, {{x + y, x + y}, {y - x, y - x}});
  }
  
  for (int i = 0; i < q; i++) {
    int t, x, y;
    scanf("%d", &t);
    
    if (t == 1) {
      int p;
      scanf("%d %d %d", &p, &x, &y);
      p--;
      sg.set(p, {{x + y, x + y}, {y - x, y - x}});
    } else {
      int l, r;
      scanf("%d %d %d %d", &l, &r, &x, &y);
      l--;
      ppii b = sg.prod(l, r);
      printf("%lld\n", max({abs((1ll * b.first.first) - (x + y)), abs((1ll * b.first.second) - (x + y)), abs((1ll * b.second.first) - (y - x)), abs((1ll * b.second.second) - (y - x))}));
    }
  }
}
