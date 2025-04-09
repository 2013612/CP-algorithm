#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int k, n;
long long l, r, a[50], ans;
vector<long long> f[21], s[21];
int main() {
	scanf("%d %d %lld %lld", &n, &k, &l, &r);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 0; i < (1 << min(n, 20)); i++) {
		int cnt = 0;
		long long sum = 0;
		int t = i;
		for (int j = 0; t != 0; j++, t >>= 1) {
			if (t & 1) {
				sum += a[j];
				cnt++;
			}
		}
		f[cnt].push_back(sum);
	}
	for (int i = 0; i < (1 << max(min(n - 20, 20), 0)); i++) {
		int cnt = 0;
		long long sum = 0;
		int t = i;
		for (int j = 0; t != 0; j++, t >>= 1) {
			if (t & 1) {
				sum += a[20 + j];
				cnt++;
			}
		}
		s[cnt].push_back(sum);
	}
	for (int i = 0; i <= 20; i++) {
		sort(f[i].begin(), f[i].end(), greater<long long>());
		sort(s[i].begin(), s[i].end());
	}
	for (int i = max(0, k - 20); i <= min(20, k); i++) {
		long long a = 0, b = 0;
		for (auto x : f[i]) {
			while (b < s[k - i].size()) {
				if (s[k - i][b] + x <= r) {
					b++;
				} else {
					break;
				}
			}
			while (a < s[k - i].size()) {
				if (s[k - i][a] + x < l) {
					a++;
				} else {
					break;
				}
			}
			ans += b - a;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
