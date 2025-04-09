#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long n, a, b, ans;
int main() {
	scanf("%lld %lld %lld", &n, &a, &b);
	if (a <= b) {
		ans = max(n - a + 1, 0ll);
	} else {
		if (n < a) {
			ans = 0;
		} else {
			ans += (n / a - 1) * b;
			long long t = n % a + 1;
			ans += min(t, b);
		}
	}
	printf("%lld\n", ans);
	return 0;
}