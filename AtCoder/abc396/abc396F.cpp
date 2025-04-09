#include<iostream>
#include<atcoder/segtree>
using namespace std;
using namespace atcoder;

int n, m, a[200005];
long long ans, ad[200005], mi[200005];

long long f(long long a, long long b) {
	return a + b;
}

long long e() {
	return 0;
}

int main() {
	scanf("%d %d", &n, &m);
	
	segtree<long long, f, e> seg(m), seg_rev(m);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		ans += seg.prod(a[i] + 1, m);
		ad[a[i]] += i - seg.get(a[i]);
		seg.set(a[i], seg.get(a[i]) + 1);
	}
	
	for (int i = n - 1; i >= 0; i--) {
		mi[a[i]] += n - 1 - i - seg_rev.get(a[i]);
		seg_rev.set(a[i], seg_rev.get(a[i]) + 1);
	}
	
	printf("%lld\n", ans);
	
	for (int i = m - 1; i >= 1; i--) {
		ans += ad[i];
		ans -= mi[i];
		printf("%lld\n", ans);
	}
	
	return 0;
}