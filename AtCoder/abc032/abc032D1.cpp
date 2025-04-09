#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<long long, long long> pll;

int n, w, a[303], b[303];
vector<pll> f, s;
int main() {
	scanf("%d %d", &n, &w);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	for (int i = 0; i < (1 << min(n, 15)); i++) {
		int t = i;
		long long p = 0, q = 0;
		for (int j = 0; t != 0; j++, t >>= 1) {
			if (t & 1) {
				p += a[j];
				q += b[j];
			}
		}
		f.push_back({q, p});
	}
	for (int i = 0; i < (1 << max(min(n - 15, 15), 0)); i++) {
		int t = i;
		long long p = 0, q = 0;
		for (int j = 0; t != 0; j++, t >>= 1) {
			if (t & 1) {
				p += a[15 + j];
				q += b[15 + j];
			}
		}
		s.push_back({q, p});
	}
	s.push_back({1e15, 1e15});
	sort(f.begin(), f.end(), greater<pll>());
	sort(s.begin(), s.end());
	long long maxi = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i].second < maxi) {
			s[i].second = maxi;
		}
		maxi = max(maxi, s[i].second);
	}
	int pos = 0;
	long long ans = 0;
	for (int i = 0; i < f.size(); i++) {
		while (s[pos].first + f[i].first <= w) {
			pos++;
		}
		if (pos != 0) {
			ans = max(ans, f[i].second + s[pos - 1].second);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
