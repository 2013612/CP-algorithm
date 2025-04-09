#include<iostream>
#include<vector>
#include<algorithm>
#include<atcoder/segtree>
using namespace std;
using namespace atcoder;

typedef pair<long long, int> pli;

int n;
vector<int> v1;
vector<pli> v2;
long long ans;

pli e() {
	return {0, 0};
}

pli sum(pli a, pli b) {
	return {a.first + b.first, a.second + b.second};
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		v1.push_back(a);
		v2.push_back({a, 0});
	}
	sort(v2.begin(), v2.end());
	v2.erase(unique(v2.begin(), v2.end()), v2.end());
	
	segtree<pli, sum, e> seg(v2.size());
	for (int i = 0; i < n; i++) {
		int pos = lower_bound(v2.begin(), v2.end(), make_pair(1ll * v1[i], 0)) - v2.begin();
		pli k = seg.prod(0, pos);
		ans += 1ll * v1[i] * k.second - k.first;
		seg.set(pos, {v1[i] * (seg.get(pos).second + 1), seg.get(pos).second + 1});
	}
	
	printf("%lld\n", ans);
	
	return 0;
}