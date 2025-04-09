#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int n, k;
long long a[200006], ans;
set<pair<int, int>> s;

vector<pair<int, int>> merge(pair<int, int> p) {
//	printf("$ %d %d\n", p.first, p.second);
	auto upper = s.upper_bound(p);
	if (upper != s.begin()) {
		upper--;
	}
	
	vector<pair<int, int>> v;
	while (upper != s.end() && (*upper).first <= p.second) {
		if (upper->second >= p.first) {
			pair<int, int> x = *upper;
			pair<int, int> t = {max(p.first, x.first), min(p.second, x.second)};
			v.push_back(t);
		}
		upper++;
	}
	
	return v;
}

void solve() {
	scanf("%d %d", &n, &k);
	
	int k2 = 2 * k;
	
	ans = 0;
	s.clear();
	
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	
	sort(a, a + n);
	
	s.insert({0, k2 - 1});
	
	for (int i = 0; i < n; i++) {
		vector<pair<int, int>> v, v2;
		v = merge({a[i] % k2, min(a[i] % k2 + k - 1, 1ll * k2 - 1)});
		
		if (a[i] % k2 + k - 1 > k2 - 1) {
			v2 = merge({0, (a[i] + k - 1) % k2});
		}
		
		s.clear();
		
		for (auto x: v) {
			s.insert(x);
		}
		for (auto x: v2) {
			s.insert(x);
		}
		
//		for (auto it: s) {
//			printf("# %d %d %d\n", i, it.first, it.second);
//		}
	}
	
	if (s.empty()) {
		printf("-1\n");
	} else {
		ans = a[n - 1];
		
		long long extra = 0;
		
		int mod = ans % k2;
		
		auto it = s.lower_bound({mod, mod});
		if (it != s.begin()) {
			it--;
		}
		if (it->second < mod) {
			it++;
		}
		
//		printf("* %d %d %d\n", mod, it->first, it->second);
		
		if (it == s.end()) {
			extra = k2 - mod + s.begin()->first;
		} else {
			if (it->first > mod) {
				extra = it->first - mod;
			}
		}
		
		printf("%lld\n", ans + extra);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	
	while (t-- > 0) {
		solve();
	}
	
	return 0;	
}