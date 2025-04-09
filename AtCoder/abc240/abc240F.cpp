#include<iostream>
using namespace std;
typedef pair<long long, long long> pll;

int t, n, m;
pll c[200006];
long long b[200006], a[200006];

long long cal(long long a, long long b, long long c) {
	return b * (b + 1) / 2 * a + c * b;
}


int main() {
	scanf("%d", &t);
	while (t > 0) {
		t--;
		scanf("%d %d", &n, &m);
		long long ans = -4e18;
		for (int i = 1; i <= n; i++) {
			long long e, f;
			scanf("%lld %lld", &e, &f);
			c[i] = {e, f};
			b[i] = b[i - 1] + e * f;
			a[i] = a[i - 1] + cal(e, f, b[i - 1]);
			int l = 1;
			int r = f + 1;
			while (l + 1 < r) {
				int mid = (l + r) / 2;
				long long m_v = cal(e, mid, b[i - 1]);
				long long l_v = cal(e, mid - 1, b[i - 1]);
				long long r_v = cal(e, mid + 1, b[i - 1]);
				if (l_v > m_v) {
					r = mid;
				} else if (r_v > m_v) {
					l = mid;
				} else {
					l = r = mid;
				}
			}
			ans = max(ans, a[i - 1] + cal(e, l, b[i - 1]));
			ans = max(ans, a[i]);
		}
		printf("%lld\n", ans);
	}
}

