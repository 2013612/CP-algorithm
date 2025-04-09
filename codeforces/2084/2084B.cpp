#include<bits/stdc++.h>
using namespace std;

int n, ans;
vector<long long> v;

long long g(long long a, long long b) {
	return b == 0 ? a : g(b, a % b);
}

void solve() {
	scanf("%d", &n);
	v.resize(n);
	ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &v[i]);
	}
	
	sort(v.begin(), v.end());
	
	long long k = 0;
	
	for (int i = 1; i < n; i++) {
		if (v[i] % v[0] == 0) {
			k = gcd(v[i], k);
		}
	}
	
	if (k == v[0]) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}