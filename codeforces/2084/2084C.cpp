#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> v1, v2, rev1, rev2;
vector<pair<int, int>> ans;

void solve() {
	scanf("%d", &n);
	v1.resize(n + 1);
	v2.resize(n + 1);
	rev1.resize(n + 1);
	rev2.resize(n + 1);
	ans.clear();
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v1[i]);
		rev1[v1[i]] = i;
	}
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v2[i]);
		rev2[v2[i]] = i;
	}
	
	if (n & 1) {
		for (int i = 1; i <= n; i++) {
			if (v1[i] == v2[i]) {
				if (i != (n + 1) / 2) {
					int ind = (n + 1) / 2;
					swap(v1[i], v1[ind]);
					rev1[v1[i]] = i;
					rev1[v1[ind]] = ind;
					swap(v2[i], v2[ind]);
					rev2[v2[i]] = i;
					rev2[v2[ind]] = ind;
					ans.push_back({i, ind});
				}
				break;
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (v1[i] == v2[n + 1 - i]) {
			continue;
		}
		
		int ind = rev1[v2[n + 1 - i]];
		swap(v1[i], v1[ind]);
		rev1[v1[i]] = i;
		rev1[v1[ind]] = ind;
		swap(v2[i], v2[ind]);
		rev2[v2[i]] = i;
		rev2[v2[ind]] = ind;
		ans.push_back({i, ind});
	}
	
	for (int i = 1; i <= n; i++) {
		if (v1[i] != v2[n + 1 - i]) {
			printf("-1\n");
			return;
		}
	}
	
//	for (int i = 1; i <= n; i++) {
//		printf("%d ", v1[i]);
//	}
//	printf("\n");
//	for (int i = 1; i <= n; i++) {
//		printf("%d ", rev1[i]);
//	}
//	printf("\n");
	
	printf("%d\n", ans.size());
	for (auto [x, y]: ans) {
		printf("%d %d\n", x, y);
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