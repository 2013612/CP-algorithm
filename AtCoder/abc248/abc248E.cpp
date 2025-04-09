#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef pair<long long, long long> pll;
typedef pair<pll, pll> ppllpll;

int n, k, x[303], y[303], f[3003], ans;
map<ppllpll, int> m;

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	for (int i = 0; i < 3000; i++) {
		f[i] = i * (i + 1) / 2;
	}
	if (k == 1) {
		printf("Infinity\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int dx = x[i] - x[j];
			int dy = y[i] - y[j];
			long long g = gcd(abs(dx), abs(dy));
			if (g != 0) {
				dx /= g;
				dy /= g;
			}
			if (dx < 0) {
				dx *= -1;
				dy *= -1;
			}
			long long c1 = dx * y[i] - dy * x[i];
			long long c2 = dx;
			long long g2 = gcd(abs(c1), abs(c2));
			if (g2 != 0) {
				c1 /= g2;
				c2 /= g2;
			}
			if (c1 < 0) {
				c1 *= -1;
				c2 *= -1;
			}
			if (dx == 0) {
				dy = 1;
				c1 = x[i];
				c2 = 1;
			}
			if (dy == 0) {
				dx = 1;
				c1 = y[i];
				c2 = 1;
			}
			m[{{dy, dx}, {c1, c2}}]++;
		}
	}
	for (auto p : m) {
		int pos = upper_bound(f, f + 3000, p.second) - f;
		if (pos >= k) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
