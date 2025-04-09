#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a[2];
long long ans;

void solve() {
	scanf("%d", &n);
	ans = 0;
	a[0].clear();
	a[1].clear();
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		a[t % 2].push_back(t);
	}
	
	sort(a[0].begin(), a[0].end());
	sort(a[1].begin(), a[1].end());
	
	if (a[1].size() == 0) {
		ans = a[0].back();
	} else if (a[0].size() == 0) {
		ans = a[1].back();
	} else {
		ans = a[1].back();
		a[1].pop_back();
		
		for (auto x: a[0]) {
			ans += x;
		}
		
		for (auto x: a[1]) {
			ans += x - 1;
		}
	}
	
	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}