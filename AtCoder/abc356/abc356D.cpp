#include<iostream>
#include<unordered_map>
#include<atcoder/modint>
using namespace std;
using namespace atcoder;

using mint = modint998244353;

long long n, m;
unordered_map<long long, mint> um;

mint find(long long x) {
	if (um.count(x)) {
		return um[x];
	}
	
	long long t = x;
	long long k = 1;
	while (t > 1) {
		k <<= 1;
		t >>= 1;
	}
	
	mint res = find(k - 1) + find(x - k);
	if (m & k) {
		res += x - k + 1;
	}
	
	um[x] = res;
	return res;
}

int main() {
	scanf("%lld %lld", &n, &m);
	um[0] = 0;
	
	printf("%d\n", find(n));
	
	return 0;
}