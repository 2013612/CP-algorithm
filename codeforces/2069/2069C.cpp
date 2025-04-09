#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int M = 998244353;

int n, a[200005], two[200005], three[200005];
long long ans, sum, b[200005];

long long pow(int a, int x) {
	if (x == 0) {
		return 1;
	}
	if (x & 1) {
		return (1ll * a * pow(a, x - 1)) % M;
	} else {
		long long k = pow(a, x / 2);
		return 1ll * k * k % M;
	}
}

long long inv(int a) {
	return pow(a, M - 2);
}

void solve() {
	scanf("%d", &n);
	ans = 0;
	sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		two[i + 1] = two[i] + (a[i] == 2);
		three[i + 1] = three[i] + (a[i] == 3);
	}
	
	for (int i = 0; i < n; i++) {
		if (a[i] == 3) {
			sum += pow(2, two[i]);
			sum %= M;
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (a[i] == 3) {
			sum -= pow(2, two[i]);
			sum %= M;
		} 
		
		b[i] = sum;
	}
	
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			long long k = b[i];
			k *= inv(pow(2, two[i]));
			k %= M;
			ans += k;
			ans %= M;
			ans -= three[n] - three[i];
			ans = (M + ans) % M;
		}
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