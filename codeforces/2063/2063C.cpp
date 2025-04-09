#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int n, l, r, ans;
set<int> e[200006];

void solve() {
	scanf("%d", &n);
	
	ans = 0;
	for (int i = 0; i < n; i++) {
		e[i].clear();
	}
	
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &l, &r);
		l--;
		r--;
		e[l].insert(r);
		e[r].insert(l);
	}
	
	if (n == 2) {
		printf("0\n");
		return;
	}
	
	int maxi = e[0].size();
	vector<int> v(1, 0);
	
	for (int i = 1; i < n; i++) {
		int k = e[i].size();
		if (k > maxi) {
			v.clear();
			v.push_back(i);
			maxi = e[i].size();
		} else if (k == maxi) {
			v.push_back(i);
		}
	}
	
	if (v.size() < 2) {
		int k = e[v[0]].size() - 1;
		for (int i = 0; i < n; i++) {
			if (i == v[0]) {
				continue;
			}
			int k2 = k + e[i].size() - 1;
			
			if (e[v[0]].count(i)) {
				k2--;
			}
			
			ans = max(ans, k2);
		}
		ans++;
	} else {
		ans = 2 * ((int)e[v[0]].size() - 1);
		int m = v.size();
		for (int i = 0; i < m; i++) {
			bool can = false;
			for (int j = i + 1; j < m; j++) {
				if (!e[v[i]].count(v[j])) {
					ans++;
					can = true;
					break;
				}
			}
			if (can) {
				break;
			}
		}
	}

	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}