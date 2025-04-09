#include<iostream>
using namespace std;

long long N, M;

long long power(long long a, long long b) {
	if (b == 0) return 1;
	if (b & 1) {
		return a * power(a, b - 1) % M;
	} else {
		long long temp = power(a, b / 2);
		return temp * temp % M;
	}
}

long long solver(long long n) {
	if (n == 0) return 0;
	
	if (n & 1) {
		return (solver(n - 1) * 10 % M + power(10, n)) % M;
	} else {
		long long temp = solver(n / 2) * power(10, n / 2) % M + power(10, n / 2) * power(10, n / 2) % M;
		return temp % M;
	}
}

int main() {
	scanf("%lld %lld", &N, &M);
	printf("%lld\n", solver(N));
	return 0;
} 
