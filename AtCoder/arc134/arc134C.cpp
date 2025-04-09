#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

using mint = modint998244353;

int n, k;

long long a[100006];

mint ans, inv[503];

mint nCr(int n, int r) {
	mint t = 1;
	for (int i = 1; i <= r; i++) {
		t *= n - i + 1;
		t *= inv[i];
	}
	return t;
}

int main() {
	for (int i = 1; i < 500; i++) {
		inv[i] = mint(i).inv();
	}
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		if (i != 0) {
			a[0] -= a[i];
		}
	}
	a[0] -= k;
	if (a[0] < 0) {
		printf("0\n");
		return 0;
	}
	ans = 1;
	for (int i = 0; i < n; i++) {
		ans *= nCr(a[i] + k - 1, k - 1);
	}
	printf("%d\n", ans);
	return 0;
}
