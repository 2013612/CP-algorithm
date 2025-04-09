#include<bits/stdc++.h>
using namespace std;

int n, k;
long long ans;
vector<int> a;
vector<pair<int, int>> b;

void solve() {
	scanf("%d %d", &n, &k);
	a.resize(n);
	b.resize(n);
	ans = 0;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = {a[i], i};
	}
	
	if (k == 1) {
		ans = a[0] + a[n - 1];
		
		for (int i = 1; i < n - 1; i++) {
			ans = max(ans, 1ll * a[i] + max(a[0], a[n - 1]));
		}
	} else {
		sort(a.begin(), a.end());
	
		for (int i = 0; i < k + 1; i++) {
			ans += a[n - i - 1];
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