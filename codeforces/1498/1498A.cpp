#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

long long gcd(long long a, long long b) {
	return b == 0? a : gcd(b, a % b);
}

long long digit(long long a) {
	return a < 10? a : a % 10 + digit(a / 10);
}

int T;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		long long N;
		scanf("%lld", &N);
		for (long long j = N; ; j++) {
			//cout << digit(j) << endl;
			//cout << gcd(j, digit(j)) << endl;
			if (gcd(j, digit(j)) > 1) {
				printf("%lld\n", j);
				break;
			}
		}
	}
	return 0;
}
