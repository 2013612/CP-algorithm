#include<iostream>
#include<algorithm>
#include<vector>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
using mint1 = static_modint<998244352>;

long long N, K, M;
mint ans;
const int MOD = 998244353;

int main() {
	scanf("%lld %lld %lld", &N, &K, &M);
	mint1 k = K;
	ans = ans.pow(k.pow(N).val());
	if (M % MOD == 0) {
		printf("0\n");
	} else {
		printf("%lld\n", ans.val());
	}
	return 0;
}
