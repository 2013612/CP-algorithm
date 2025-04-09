#include<iostream>
#include<vector>
#include<algorithm>
#include<atcoder/segtree>
using namespace std;
using namespace atcoder;

const int M = 2e6;
const int L = 3e6;

int n;
long long ans = 0;

long long op(long long a, long long b) {
	return a + b;
}

long long e() {
	return 0;
}

void solve() {
	scanf("%d", &n);
	string s;
	cin >> s;
	
	segtree<long long, op, e> st(L);
	
	st.set(M, 1);
	
	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			cur++;
		} else {
			cur -= 3;
		}
		
		ans += st.prod(0, cur - 1 + M);
		ans += st.get(cur + 1 + M);
		
//		printf("!! %d %lld %lld\n", i, st.prod(0, cur - 1 + M), st.get(cur + 1 + M));
		
		st.set(cur + M, st.get(cur + M) + 1);
	}
	
	printf("%lld\n", ans);
}

int main() {
	solve();
	
	return 0;
}