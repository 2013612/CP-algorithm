#include<iostream>
#include<vector>
#include<algorithm>
#include<atcoder/segtree>
using namespace std;
using namespace atcoder;

int n, q, a[200006], ans;

struct S {
	int swe;
	long long max_l;
	long long max_r;
	long long min_l;
	long long min_r;
	long long maxi = 0;
	int size = 1;
	
	S(int a) {
		swe = a;
		max_l = a;
		max_r = a;
		min_l = a;
		min_r = a;
	}
	
	void pr() {
		printf("print S: %d %lld %lld %lld %lld %lld %d\n", swe, max_l, max_r, min_l, min_r, maxi, size);
	}
};

S op(S a, S b) {
	S temp = S(max(a.swe, b.swe));
	temp.max_l = max(a.max_l, b.max_l - a.size);
	temp.min_l = min(a.min_l, b.min_l + a.size);
	temp.max_r = max(a.max_r - b.size, b.max_r);
	temp.min_r = min(a.min_r + b.size, b.min_r);
	temp.maxi = max({0ll, a.maxi, b.maxi, a.max_r - b.min_l - 1, b.max_l - a.min_r - 1});
	temp.size = a.size + b.size;
	return temp;
}

S e() {
	S temp = S(0);
	temp.max_l = -2e12;
	temp.min_l = 2e12;
	temp.max_r = -2e12;
	temp.min_r = 2e12;
	temp.maxi = 0;
	temp.size = 0;
	return temp;
}

void solve() {
	scanf("%d %d", &n, &q);
	
	vector<S> v;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		v.push_back(S(a[i]));
	}
	
	segtree<S, op, e> seg(v);
	
//	op(e(), S(1)).pr();
//	op(S(1), e()).pr();

	printf("%lld\n", seg.all_prod().maxi);
	
	for (int i = 0; i < q; i++) {
		int p, x;
		scanf("%d %d", &p, &x);
		p--;
		seg.set(p, S(x));
		printf("%lld\n", seg.all_prod().maxi);
	}
//	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}