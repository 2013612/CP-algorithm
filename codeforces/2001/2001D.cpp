#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<atcoder/segtree>
using namespace std;
using namespace atcoder;

int n, last;
vector<int> v[300005], ans;
vector<pair<int, int>> en, a;
set<int> s;

pair<int, int> op(pair<int, int> a, pair<int, int> b) {
	return {max(a.first, b.first), min(a.second, b.second)};
}

pair<int, int> e() {
	return {-1e9, 1e9};
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		v[i].clear();
	}
	en.clear();
	a.clear();
	ans.clear();
	s.clear();
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		a.push_back({k, k});
		v[a[i].first].push_back(i);
		s.insert(a[i].first);
	}
	
	segtree<pair<int, int>, op, e> seg(a);
	
	for (auto x: s) {
		en.push_back({v[x].back(), x});
	}
	
	sort(en.begin(), en.end());
	
	int p = 0;
	int q = 0;
	int last = 0;
	for (int i = 0; i < n; i++) {
		while (q < n && en[q].first == i) {
			if (!s.count(en[q].second)) {
				q++;
				continue;
			}
			while (true) {
//				printf("! %d %d\n", last, i + 1);
				pair<int, int> x = seg.prod(last, i + 1);
				int temp;
				if (ans.size() & 1) {
					temp = x.second;
				} else {
					temp = x.first;
				}
				ans.push_back(temp);
				s.erase(temp);
				for (int j = 0; j < v[temp].size(); j++) {
					if (v[temp][j] >= last) {
						last = v[temp][j] + 1;
						break;
					}
				}
				for (int j = 0; j < v[temp].size(); j++) {
					seg.set(v[temp][j], e());
				}
				
				if (temp == en[q].second) {
					break;
				}
			}
			q++;
		}
	}
	
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
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