#include<iostream>
using namespace std;

int n, m, q;
bool a[26], b[26];
string s, t;

int main() {
  scanf("%d %d", &n, &m);
  cin >> s;
  cin >> t;
  for (int i = 0; i < n; i++) {
    a[s[i] - 'a'] = true;
  }
  for (int i = 0; i < m; i++) {
    b[t[i] - 'a'] = true;
  }
  
  scanf("%d", &q);
  
  for (int i = 0; i < q; i++) {
    string p;
    cin >> p;
    bool u = true, v = true;
    for (auto x: p) {
      u = u && a[x - 'a'];
      v = v && b[x - 'a'];
    }
    
    if (u && v) {
      printf("Unknown\n");
    } else if (u) {
      printf("Takahashi\n");
    } else {
      printf("Aoki\n");
    }
  }
  
  return 0;
}