#include<bits/stdc++.h>
using namespace std;

int n, m;
long long ans;
vector<int> a;
vector<long long> pre;

void solve() {
	scanf("%d %d", &n, &m);
	a.resize(m);
	pre.resize(m + 1);
	pre[0] = 0;
	ans = 0;
	
	for (int i = 0; i < m; i++) {
		scanf("%d", &a[i]);
		
		a[i] = min(a[i], n - 1);
	}
	
	sort(a.begin(), a.end());
	
	for (int i = 0; i < m; i++) {
		pre[i + 1] = pre[i] + a[i];
	}
	
	int l = 0, r = m - 1;
	
	while (l < r) {
//		printf("!! %d %d %d %d \n", l, r, a[l], a[r]);
		if (a[l] + a[r] < n) {
			l++;
			continue;
		}
		
		long long sum = pre[r] - pre[l];
		sum += 1ll * (r - l) * a[r];
		sum -= 1ll * (r - l) * (n - 1);
		ans += sum;
		r--;
	}
	
	printf("%lld\n", ans * 2);

}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}