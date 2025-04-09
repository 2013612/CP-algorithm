#include<iostream>
#include<algorithm>
#include<vector>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

long long n;
mint ans;
int main() {
	scanf("%lld", &n);
	long long t = 10;
	while (n >= t) {
		mint p = t - t / 10;
		p = p * (p + 1) / 2;
		ans += p;
		t *= 10;
	}
	mint p = n - t / 10 + 1;
	p = p * (p + 1) / 2;
	ans += p;
	printf("%d\n", ans);
	return 0;
}
