#include<bits/stdc++.h>
using namespace std;

int n, a[300006];
long long ans;
set<int> s[2];

void solve() {
	scanf("%d", &n);
	s[0].clear();
	s[1].clear();
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 1; i <= n / 2 + 1; i++) {
		s[0].insert(i);
		s[1].insert(i);
	}
	
	ans = 0;
	long long t = 0;
	
	int cur = 1;
	int l = 0, r = n - 1;
	
	while (l <= r) {
		while (a[l] < *s[0].begin()) {
			l++;
		}
		
		if (l > r) {
			break;
		}
		
		{
			auto x = s[0].upper_bound(a[l]);
			x--;
			s[0].erase(x);
			
			t -= l;
			l++;
		}
		
		while (a[r] < *s[1].begin()) {
			r--;
		}
		
		if (l > r) {
			break;
		}
		
		{
			auto x = s[1].upper_bound(a[r]);
			x--;
			s[1].erase(x);
			
			t += r;
			r--;
		}
		
		ans = max(ans, t);
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