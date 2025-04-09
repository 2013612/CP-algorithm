#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int n;
mint a[3003][3003], pow[3003];

int main() {
	scanf("%d", &n);
	a[0][0] = 1;
	pow[0] = 1;
	for (int i = 1; i < 3003; i++) {
		pow[i] = pow[i - 1] * 2;
	}
	for (int i = 1; i < n; i++) {
		mint sum = 0;
		for (int j = 0; j < i; j++) {
			mint p = pow[i - j];
			a[i][0] += a[i - 1][j] * (p - 1) / p;
		}
		a[i][0] = (1 - a[i][0]) * pow[i] / (pow[i + 1] - 1);
		for (int j = 1; j <= i; j++) {
			a[i][j] = a[i][j - 1] / 2 + a[i - 1][j - 1] / 2;
		}
	}
	
	for (int i = 0; i < n; i++) {
		printf("%d%c", a[n - 1][i], i == n - 1 ? '\n': ' ');
	}
	
	return 0;
}