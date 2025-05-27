#include<iostream>
#include<algorithm>
#include<atcoder/modint>
using namespace std;
using namespace atcoder;

using mint = modint998244353;

int t, k;
long long n;
mint ans, fac[103];

mint ncr(int n, int r) {
	if (n < r) {
		return 0;
	}
	
	return fac[n] / fac[r] / fac[n - r];
}

int main() {
	scanf("%d", &t);
	
	fac[0] = 1;
	for (int i = 1; i <= 60; i++) {
		fac[i] = fac[i - 1] * i;
	}
	
	for (int i = 0; i < t; i++) {
		scanf("%lld %d", &n, &k);
		ans = 0;
		string s = "";
		while (n > 0) {
			s.push_back('0' + (n & 1));
			n >>= 1;
		}
		
		int m = s.size();
		int cnt = 0;
		mint sum = 0;
		for (int j = m - 1; j >= 0 && cnt < k; j--) {
			if (s[j] == '1') {
				ans += ncr(j - 1, k - cnt - 1) * ((1ll << j) - 1);
				ans += ncr(j, k - cnt) * sum;
				
				cnt++;
				
				sum += 1ll << j;
			}
		}
		
		ans += (cnt == k) * sum;
		
		printf("%d\n", ans.val());
	}
	
	return 0;
}