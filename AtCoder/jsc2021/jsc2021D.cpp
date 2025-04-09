#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int M = 1e9 + 7;
long long N, P, ans;

long long power(long long a, long long b) {
	if (b == 0) {
		return 1;
	}
	if (b & 1) {
		return a * power(a, b - 1) % M;
	} else {
		long long temp = power(a, b / 2);
		return temp * temp % M;
	}
}

int main() {
	scanf("%lld %lld", &N, &P);
	ans = ((P - 1) * power(P - 2, N - 1)) % M;
	printf("%lld\n", ans);
}
