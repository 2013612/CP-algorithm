#include<bits/stdc++.h>
#include<atcoder/segtree>
using namespace std;
using namespace atcoder;

int n, a[300006];
long long ans;

int f(int a, int b) {
	return a + b;
}

int e() {
	return 0;
}

void solve() {
	scanf("%d", &n);
	
	vector<int> o, st, v1, v2;
	segtree<int, f, e> seg(n + 10);
	ans = 0;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		o.push_back(a[i]);
		if (i & 1) {
			v2.push_back(a[i]);
		} else {
			v1.push_back(a[i]);
		}
		
		ans += seg.prod(a[i] + 1, n + 1);
		seg.set(a[i], 1);
	}
	
//	printf("%lld\n", ans);
	
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	segtree<int, f, e> seg2(n + 10);
	
	long long p = 0;
	
	for (int i = 0; i < n / 2; i++) {
		p += seg2.prod(v1[i] + 1, n + 1);
		seg2.set(v1[i], 1);
		st.push_back(v1[i]);
		p += seg2.prod(v2[i] + 1, n + 1);
		seg2.set(v2[i], 1);
		st.push_back(v2[i]);
	}
	
	if (n & 1) {
		p += seg2.prod(v1.back() + 1, n + 1);
		st.push_back(v1.back());
	}
	
//	printf("%lld\n", p);
	
	if ((abs(p - ans) % 2) != 0) {
		swap(st[n - 3], st[n - 1]);
	}
	
	for (auto x: st) {
		printf("%d ", x);
	}
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}