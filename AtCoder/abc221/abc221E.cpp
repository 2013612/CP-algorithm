#include<iostream>
#include<map>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

using mint = modint998244353;

const int M = 998244353;
int N, a[300006];
map<int, int> my_map, b;
mint ans;

mint op(mint a, mint b) {
	return a + b;
}

mint e() {
	return 0;
}

segtree<mint, op, e> seg(300006);

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		my_map[a[i]]++;
	}
	int cnt = 0;
	for (auto x:my_map) {
		b[x.first] = cnt;
		cnt++;
	}
	for (int i = 1; i < N; i++) {
		seg.set(b[a[i]], seg.get(b[a[i]]) + pow_mod(2, i - 1, M));
	}
	for (int i = 0; i < N - 1; i++) {
		ans = ans + seg.prod(b[a[i]], N) * inv_mod(pow_mod(2, i, M), M);
		seg.set(b[a[i + 1]], seg.get(b[a[i + 1]]) - pow_mod(2, i, M));
	}
	printf("%d\n", ans.val());
	return 0;
}
