#include<iostream>
#include<math.h>
using namespace std;

long long n, ans;

int main() {
	scanf("%lld", &n);
	
	for (int i = 1; (1ll << i) <= n; i++) {
		long double k = (1ll << i);
		k = n / k;
		int p = sqrt(k);
		ans += (p + 1) / 2;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}