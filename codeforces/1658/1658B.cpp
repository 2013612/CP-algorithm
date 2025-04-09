#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

const int M = 998244353;
int t, n;
long long fac[1004], ans;

int main() {
	scanf("%d", &t);
	fac[0] = 1;
	for (int i = 1; i <= 1000; i++) {
		fac[i] = i * fac[i - 1] % M;
	}
	
	while (t-- > 0) {
		scanf("%d", &n);
		ans = 0;
		if (n % 2 == 0) {
			ans = fac[n / 2] * fac[n / 2] % M;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
