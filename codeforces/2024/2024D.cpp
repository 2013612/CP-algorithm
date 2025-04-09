#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, a[200006], b[200006];
long long sum, ans;

void solve() {
	scanf("%d", &n);
	
	vector<long long> v(n, 1e18);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		b[i]--;
	}
	
	sum = 0;
	ans = 0;
	v[0] = 0;
	
	for (int i = 0; i < n; i++) {
		sum += a[i];
		ans = max(ans, sum - v[i]);
		
		printf("! %d %lld %lld\n", i, sum, v[i]);
		
		if (b[i] > i) {
			v[b[i]] = min(v[b[i]], v[i] + a[i]);
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