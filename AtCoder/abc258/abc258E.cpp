#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int n, q, x, a[200006];
long long w[400006], sum[400006], w_sum;
vector<int> v, v2;

int main() {
	scanf("%d %d %d", &n, &q, &x);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &w[i]);
		w[n + i] = w[i];
		w_sum += w[i];
	}
	for (int i = 1; i <= 2 * n; i++) {
		sum[i] = sum[i - 1] + w[i];
	}
	for (int i = 1; i <= n; i++) {
		long long temp = x % w_sum;
		int ind = lower_bound(sum, sum + 2 * n + 1, sum[i - 1] + temp) - sum;
		if (ind > n) {
			ind -= n;
		}
		a[i] = ind + 1;
		if (a[i] > n) {
			a[i] -= n;
		}
//		printf("%d %d\n", ind, a[i]);
	}
//	printf("\n");
	set<int> s;
	v.push_back(1);
	s.insert(1);
	while (s.count(a[v.back()]) == 0) {
//		printf("! %d\n", v.back());
		v.push_back(a[v.back()]);
		s.insert(v.back());
	}
//	for (auto x : v) {
//		printf("%d ", x);
//	}
//	printf("\n");
	v2.push_back(a[v.back()]);
	while (v2.back() != v.back()) {
//		printf("!%d %d\n", v.back(), v2.back());
		v2.push_back(a[v2.back()]);
	}
	for (int i = 0; i < q; i++) {
		long long k;
		scanf("%lld", &k);
		
		long long ans = 0;
		
		if (x % w_sum == 0) {
			ans = x / w_sum * n;
		} else if (k <= v.size()) {
			if (a[v[k - 1]] <= v[k - 1]) {
				ans = (a[v[k - 1]] + n - v[k - 1]) + x / w_sum * n;
			} else {
				ans = a[v[k - 1]] - v[k - 1] + x / w_sum * n;
			}
			
		} else {
			int t = (k - v.size()) % v2.size();
			t = (t - 1 + v2.size()) % v2.size();
			if (a[v2[t]] <= v2[t]) {
				ans = (a[v2[t]] + n - v2[t]) + x / w_sum * n;
			} else {
				ans = a[v2[t]] - v2[t] + x / w_sum * n;
			}
			
		}
		
		printf("%lld\n", ans);
	}
	return 0;
}