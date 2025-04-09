#include<iostream>
using namespace std;

const int M = 1000000007;
long long H, W, A, B, ans, fac[300006];

long long inv(long long a, long long b) {
	if (b == 0) {
		return 1;
	}
	if (b == 1) {
		return a;
	}
	if (b % 2 == 0) {
		long long temp = inv(a, b/2);
		return temp * temp % M;
	} else {
		return a * inv(a, b - 1) % M;
	}
}

int main() {
	cin >> H >> W >> A >> B;
	fac[0] = 1;
	for (int i = 1; i < 210000; i++) {
		fac[i] = fac[i - 1] * i % M;
	}
	H = H - 1;
	W = W - 1;
	ans = fac[H + W] * inv(fac[H], M - 2) % M;
	ans = ans * inv(fac[W], M - 2) % M;
	//cout << ans << endl;
	for (int i = 0; i < B; i++) {
		//cout << i << endl;
		long long temp = fac[H - A + i] * inv(fac[H - A], M - 2) % M;
		temp = temp * inv(fac[i], M - 2) % M;
		temp = temp * fac[W + A - 1 - i] % M;
		temp = temp * inv(fac[A - 1], M - 2) % M;
		temp = temp * inv(fac[W - i], M - 2) % M;
		ans = ans - temp;
		ans = ans % M;
		//cout << temp << endl;
	}
	ans = (ans + M) % M;
	cout << ans << endl;
	return 0;
}
