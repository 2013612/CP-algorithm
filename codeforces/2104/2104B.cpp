#include<bits/stdc++.h>
using namespace std;

int n, a[300006];
long long ans;

void solve() {
	scanf("%d", &n);
	ans = 0;
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		m[a[i]]++;
	}
	
	for (int i = n - 1; i >= 0; i--) {
		int maxi = m.rbegin()->first;
		printf("%lld ", ans + maxi);
		
		ans += a[i];
		m[a[i]]--;
		if (m[a[i]] == 0) {
			m.erase(a[i]);
		}
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