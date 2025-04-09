#include<iostream>
#include<atcoder/modint>
using namespace std;
using namespace atcoder;

using mint = modint998244353;

int n, a[300006];
mint ans, prefix[300006];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		prefix[i + 1] = prefix[i] + a[i];
	}
	
	for (int i = 1; i < n; i++) {
		int k = a[i];
		mint ten = 1;
		while (k > 0) {
			ten *= 10;
			k /= 10;
		}
		ans += prefix[i] * ten + 1ll * a[i] * i;
	}
	
	printf("%d\n", ans);
	
	return 0;
}