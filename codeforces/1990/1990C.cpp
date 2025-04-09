#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int n, a[200006];
set<int> s;
long long ans = 0;

void solve() {
	scanf("%d", &n);
	ans = 0;
	int maxi = 0;
	s.clear();
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		ans += a[i];
	}
	for (int i = 0; i < n; i++) {
		if (s.count(a[i])) {
			maxi = max(maxi, a[i]);
		} else {
			s.insert(a[i]);
		}
		a[i] = maxi;
	}
	
	maxi = 0;
	s.clear();
	for (int i = 0; i < n; i++) {
		ans += a[i];
	}
	for (int i = 0; i < n; i++) {
		if (s.count(a[i])) {
			maxi = max(maxi, a[i]);
		} else {
			s.insert(a[i]);
		}
		a[i] = maxi;
	}
	
	int cnt = 1;
	for (int i = n - 1; i >= 0; i--) {
//		printf("!!%lld\n", ans);
		ans += 1ll * cnt * a[i];
		cnt++;
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