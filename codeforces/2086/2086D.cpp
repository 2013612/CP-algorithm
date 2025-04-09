#include<iostream>
#include<vector>
#include<map>
using namespace std;

const int M = 998244353;

int n;
vector<int> a;
map<int, int> m[30];
long long fac[500005], ans, sum;

long long pow(long long a, long long x) {
	if (x == 0) {
		return 1;
	}
	
	if (x & 1) {
		return (1ll * a * pow(a, x - 1)) % M;
	} else {
		long long k = pow(a, x / 2);
		return (k * k) % M;
	}
}

long long inv(long long a) {
	return pow(a, M - 2);
}

void init() {
	fac[0] = 1;
	for (int i = 1; i <= 500001; i++) {
		fac[i] = fac[i - 1] * i % M;
	}
}

void solve() {
//	scanf("%d", &n);
	n = 26;
	a.resize(n);
	ans = 0;
	sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		m[i].clear();
		sum += a[i];
	}
	m[n].clear();
	
	ans = fac[sum / 2] * fac[(sum + 1) / 2] % M;
	
	m[0][0] = 1;
	
	for (int i = 0; i < n; i++) {
		for (auto [x, y]: m[i]) {
			m[i + 1][x] += y;
			
			if (a[i] > 0 && (x + a[i] <= (sum + 1) / 2)) {
				m[i + 1][x + a[i]] += y;
			}
		}
	}
	
	ans *= m[n][sum / 2];
	ans %= M;
	
	for (int i = 0; i < n; i++) {
		if (a[i] != 0) {
			ans *= inv(fac[a[i]]);
			ans %= M;
		}
	}
	
	printf("%lld\n", ans);
}

int main() {
	init();
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}