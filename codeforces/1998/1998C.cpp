#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int a[200006], b[200006], pre[200006];
pair<long long, int> c[200006];
vector<long long> pre_sum;

void solve() {
	int n, k;
	scanf("%d %d", &n, &k);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		c[i] = {a[i], b[i]};
	}
	sort(c, c + n);
	
	long long ans = 0;
	pre_sum.clear();
	pre_sum.push_back(0);
	for (int i = 0; i < n; i++) {
		pre[i + 1] = pre[i] + c[i].second;
		if (c[i].second) {
			pre_sum.push_back(c[i].first + pre_sum.back());
		}
	}
	
	for (int i = 0; i < n; i++) {
		int medi = n/2 - (i >= n/2);
		if (c[i].second) {
			ans = max(ans, c[medi].first + c[i].first + k);
			continue;
		}
		
		long long left = 0;
		long long right = 4e9 + 1;
		while (left + 1 < right) {
			long long mid = (left + right) / 2;
			int pos = lower_bound(c, c + n, make_pair(mid, 0)) - c;
			if (pos == i) {
				pos++;
			}
			int need = pos - medi - (pos > i && i >= medi);
			int n_pos = pos;
			if (n_pos - 1 == i) {
				n_pos--;
			}
			
			if (need <= 0 || (pre[n_pos] >= need && (pre_sum[pre[n_pos]] - pre_sum[pre[n_pos] - need] + k >= 1ll * mid * need))) {
				left = mid;
			} else {
				right = mid;
			}
		}
		
		ans = max(ans, c[i].first + left);
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