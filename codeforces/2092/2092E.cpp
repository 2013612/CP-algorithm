#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

long long n, m, k, ans, cnt[2];

long long pow(int a, long long x) {
	if (x == 0) {
		return 1;
	}
	
	if (x & 1) {
		return 1ll * a * pow(a, x - 1) % M;
	} else {
		long long t = pow(a, x / 2);
		return t * t % M;
	}
}

bool is_b(int x, int y) {
	if (x == 1 && y == 1) {
		return false;
	}
	
	if (x == 1 && y == m) {
		return false;
	}
	
	if (x == n && y == 1) {
		return false;
	}
	
	if (x == n && y == m) {
		return false;
	}
	
	return x == 1 || y == 1 || x == n || y == m;
}

void solve() {
	scanf("%lld %lld %lld", &n, &m, &k);
	cnt[0] = cnt[1] = 0;
	int border = (n + m - 4) * 2;
	ans = n * m - 1;
	
	for (int i = 0; i < k; i++) {
		int x, y, c;
		scanf("%d %d %d", &x, &y, &c);
		
		if (is_b(x, y)) {
			cnt[c]++;
			border--;
		}
		
		ans--;
	}
	
	if (border == 0 && (cnt[0] & 1)) {
		printf("0\n");
		return;
	}
	
	if (border == 0) {
		ans++;
	}
	
	printf("%lld\n", pow(2, ans));
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}