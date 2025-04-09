#include<iostream>
using namespace std;

int T, N, M;
int fac[200006], two[200006];
const int K = 1000000007;

int big_mod(int x, int y, int z) {
	if (y == 0) return 1;
	if (y % 2 == 0) return big_mod(1ll*x*x % z, y/2, z);
	else return 1ll * x * big_mod(x, y - 1, z) % z;
}

int com(int x, int y) {
	return (1ll*fac[x]*big_mod(fac[y], K - 2, K) % K)*big_mod(fac[x - y], K - 2, K) % K;
}

int main(){
	freopen("C-large-practice.in", "r", stdin);
	freopen("C-large-practice.out", "w", stdout);
	fac[0] = 1;
	two[0] = 1;
	for (int i = 1; i < 200006; i++) {
		fac[i] = 1ll*fac[i - 1]*i % K;
	}
	for (int i = 1; i < 200006; i++) {
		two[i] = 2*two[i - 1] % K;
	}
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);
		int ans = fac[2 * N];
		for (int j = 1; j <= M; j++) {
			if (j % 2) {
				int temp = 1ll*com(M, j)*fac[2*N - j] % K;
				temp = 1ll*temp*two[j] % K;
				ans = ans - temp;
				ans = (ans + K) % K;
			} else {
				int temp = 1ll*com(M, j)*fac[2*N - j] % K;
				temp = 1ll*temp*two[j] % K;
				ans = (ans + temp) % K;
			}
		}
		printf("Case #%d: %d\n", i + 1, ans);
	}
	return 0;
}
