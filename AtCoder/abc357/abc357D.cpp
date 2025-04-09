#include<iostream>
using namespace std;

const int M = 998244353;

long long n;

int pow(int a, long long b) {
	if (b == 0) {
		return 1;
	}
	if (b & 1) {
		return 1ll * a * pow(a, b - 1) % M;
	} else {
		int t = pow(a, b / 2);
		return 1ll * t * t % M;
	}
}

int main() {
	scanf("%lld", &n);
	
	long long ten = 1;
	long long temp = n;
	while (temp > 0) {
		temp /= 10;
		ten *= 10;
		ten %= M;
	}
	
	int ans = (pow(ten, n) + M - 1) % M;
	ans = (1ll * ans * pow(ten - 1, M - 2)) % M;
	ans = (1ll * (n % M) * ans) % M;
	
	printf("%d\n", ans);
	
	return 0;
}