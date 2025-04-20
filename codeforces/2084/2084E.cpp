#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int n, m, k, b[5004], v[5004];
bool vis[5004];
long long ans, fac[5004], inv[5004], d[5004][5004];

long long power(int a, long long x) {
	if (x == 0) {
		return 1;
	}
	
	if (x & 1) {
		return 1ll * a * power(a, x - 1) % M;
	} else {
		long long t = power(a, x / 2);
		return t * t % M;
	}
}

long long perm(int n, int r) {
	return fac[n] * inv[n - r] % M;
}

long long cal(int c1, int c2, int t) {
	return perm(c1, c2) * fac[t - c2] % M;
}

void solve() {
	scanf("%d", &n);
	
	for (int i = 0; i <= n; i++) {
		b[i] = 0;
		vis[i] = false;
		for (int j = 0; j <= n; j++) {
			d[i][j] = 0;
		}
	}
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		
		b[i + 1] = b[i] + (v[i] == -1);
		
		if (v[i] != -1) {
			vis[v[i]] = true;
		}
	}
	
	ans = 0;
	
	int l = n;
	for (int i = 0; i < n; i++) {
		int r = n;
		for (int j = n - 1; j >= i; j--) {
			int neg = b[j + 1] - b[i];
			int mini = min(l, r);
			
			d[neg][0]++;
			d[neg][mini]--;
			
			if (v[j] != -1) {
				r = min(r, v[j]);
			}
		}
		
		if (v[i] != -1) {
			l = min(l, v[i]);
		}
	}

	for (int i = 0; i <= b[n]; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] += d[i][j - 1];
			d[i][j] %= M;
		}
	}
	
	int cnt = 0;
	for (int j = 0; j < n; j++) {
		cnt += !vis[j];
		for (int i = cnt; i <= b[n]; i++) {
			ans += 1ll * d[i][j] * cal(i, cnt, b[n]) % M;
			ans %= M;
		}
	}
	
	printf("%lld\n", ans);
}

void init() {
	fac[0] = 1;
	inv[0] = 1;
	for (int i = 1; i <= 5000; i++) {
		fac[i] = fac[i - 1] * i % M;
		inv[i] = power(fac[i], M - 2);
	}
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