#include<bits/stdc++.h>
#include<atcoder/segtree>
using namespace std;

constexpr int B = 5;
int mod[B] = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};
int base[B];
struct Hash {
  long long h1, h2, pw;
};
using T = array<Hash, B>;
T op(T lhs, T rhs) {
  T res;
  for (int i = 0; i < B; i++) {
    res[i].h1 = (lhs[i].h1 * rhs[i].pw + rhs[i].h1) % mod[i];
    res[i].h2 = (lhs[i].h2 + lhs[i].pw * rhs[i].h2) % mod[i];
    res[i].pw = lhs[i].pw * rhs[i].pw % mod[i];
  }
  return res;
}
T e() {
  T res;
  for (int i = 0; i < B; i++) res[i] = {0, 0, 1};
  return res;
}
using SegTree = atcoder::segtree<T, op, e>;
T gen(char c) {
  T res;
  for (int i = 0; i < B; i++) res[i].h1 = res[i].h2 = c, res[i].pw = base[i];
  return res;
}


int n;
string s, ans;

int main() {
	mt19937_64 rng(time(0));
  for (int i = 0; i < B; i++) base[i] = rng() % mod[i];
  
	cin >> s;
	n = s.length();
	
	vector<T> init(n);
  for (int i = 0; i < n; i++) init[i] = gen(s[i]);
  SegTree seg{init};
	
	for (int i = 0; i < n; i++) {
		int l = i;
		int r = n;
		
		auto h = seg.prod(l, r);
	      bool flag = true;
	      for (int i = 0; i < B; i++) flag &= h[i].h1 == h[i].h2;
	      
	    if (flag) {
//	    	printf("! %d\n", i);
	    	ans.resize(n + i);
	    	for (int j = 0; j < (n + i + 1) / 2; j++) {
	    		ans[j] = ans[(n + i) - j - 1] = s[j];
			}
			cout << ans << endl;
			break;
		}
	}
	
	return 0;
}