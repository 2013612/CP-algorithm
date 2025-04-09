#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

typedef pair<int, pair<int, int>> pipii;

int n, q;
pipii a[200006];
long long ans;
set<int> s;
set<pair<int, int>> intervals;

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 0; i < q; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		a[i] = {t3, {t1, t2}};
	}
	sort(a, a + q);
	
	for (int i = 1; i <= n; i++) {
		s.insert(i);
	}
	
	for (int i = 0; i < q; i++) {
		{
			auto low = s.lower_bound(a[i].second.first);
			auto high = low;
			int cnt = 0;
			while (high != s.end() && *high <= a[i].second.second) {
				cnt++;
				high++;
			}
			ans = ans + 1ll * cnt * a[i].first;
			s.erase(low, high);
		}
		
		{
			auto upper = intervals.upper_bound(a[i].second);
			if (upper != intervals.begin()) {
				upper--;
			}
			vector<pair<int, int>> v;
			while (upper != intervals.end() && (*upper).first <= a[i].second.second) {
				if (upper->second >= a[i].second.first) {
					v.push_back(*upper);
				}
				upper++;
			}
			ans += 1ll * v.size() * a[i].first;
			pair<int, int> p = a[i].second;
			for (auto x: v) {
				p = {min(p.first, x.first), max(p.second, x.second)};
				intervals.erase(x);
			}
			intervals.insert(p);
		}
	}
	
	if (intervals.empty() || *(intervals.begin()) != make_pair(1, n)) {
		ans = -1;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}