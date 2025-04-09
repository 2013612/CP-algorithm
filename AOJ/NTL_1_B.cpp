#include<iostream>
using namespace std;
const int M = 1000000007;

long long m, n;

long long pow(long long a, long long b) {
	if (b == 0) {
		return 1;
	}
	if (b & 1) {
		return a * pow(a, b - 1) % M;
	} else {
		long long t = pow(a, b / 2);
		return t * t % M;
	}
}

int main() {
	scanf("%lld %lld", &m, &n);
	printf("%lld\n", pow(m, n));
	return 0;
}
