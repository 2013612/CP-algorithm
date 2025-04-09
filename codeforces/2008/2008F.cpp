#include<iostream>
using namespace std;

const int M = 1e9 + 7;

int a[200006], suf[200006], ans;

int pow(int a, int b) {
	if (b == 0) {
		return 1;
	}
	
	if (b & 1) {
		return 1ll * a * pow(a, b - 1) % M;
	} else {
		long long k = pow(a, b / 2);
		return k * k % M;
	}
}

void solve() {
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	int sum = a[n - 1];
	int ans = 0;
	
	for (int i = n - 2; i >= 0; i--) {
		ans = (ans + 1ll * a[i] * sum % M) % M;
		sum = (sum + a[i]) % M;
	}
	
	ans = 1ll * ans * pow((1ll * n * (n - 1) / 2) % M, M - 2) % M;
	
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}