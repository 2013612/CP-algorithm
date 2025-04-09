#include<iostream>
#include<atcoder/segtree>
using namespace std;
using namespace atcoder;

int n, p[200005];
long long ans;

int f(int a, int b) {
	return a + b;
}

int e() {
	return 0;
}

long long g(int st, int en) {
	return 1ll * (st + en) * (en - st + 1) / 2;
}

int main() {
	scanf("%d", &n);
	
	segtree<int, f, e> seg(n + 1);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		
		int cnt = seg.prod(p[i], n + 1);
		ans += g(i - cnt + 1, i);
		seg.set(p[i], 1);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}