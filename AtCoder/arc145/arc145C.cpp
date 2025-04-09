#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

using mint = modint998244353;

int n;
mint fac[400006];
int main() {
	scanf("%d", &n);
	fac[0] = 1;
	for (int i = 1; i <= 2 * n; i++) {
		fac[i] = fac[i - 1] * i;
	}
	mint two = 2;
	
	printf("%d\n", fac[2 * n] - fac[n] * (fac[n] - 1) * two.pow(n));
	return 0;
}
