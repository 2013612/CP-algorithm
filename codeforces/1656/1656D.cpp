#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t;
int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		long long n;
		scanf("%lld", &n);
		long long p = n & -n;
		printf("%lld\n", p == n ? -1 : min(2 * p, n / p));
	}
	return 0;
}
