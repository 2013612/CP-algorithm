#include<iostream>
#include<atcoder/segtree>
using namespace std;
using namespace atcoder;

const int M = 5e5 + 5;

int f(int a, int b) {
  return a + b;
}

int e() {
  return 0;
}

int n;
string s;
long long ans;

int main() {
  scanf("%d", &n);
  cin >> s;
  
  int sum = 0;
  segtree<int, f, e> st(2 * M);
  st.set(M, 1);
  
  for (int i = 0; i < n; i++) {
    int t = 0;
    if (s[i] == 'A') {
      t = 1;
    } else if (s[i] == 'B') {
      t = -1;
    }
    
    sum += t;
    
    ans += st.prod(0, sum + M);
    
    st.set(sum + M, st.get(sum + M) + 1);
  }
  
  printf("%lld\n", ans);
  
  return 0;
}