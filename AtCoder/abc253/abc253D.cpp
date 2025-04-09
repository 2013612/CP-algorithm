#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long n, a, b, ans;

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}

int main() {
	scanf("%lld %lld %lld", &n, &a, &b);
	ans = n * (n + 1) / 2;
	ans -= a * (n / a) * ((n / a) + 1) / 2;
	ans -= b * (n / b) * ((n / b) + 1) / 2;
	long long t = lcm(a, b);
	ans += t * (n / t) * ((n / t) + 1) / 2;
	printf("%lld\n", ans);
	return 0;
}