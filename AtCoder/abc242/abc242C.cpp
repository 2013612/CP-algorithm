#include<iostream>
#include<vector>
#include<algorithm>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

using mint = modint998244353;

int n;
mint a[1000006][20], ans;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= 9; i++) {
		a[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= 9; j++) {
			a[i][j] += a[i - 1][j];
			a[i][j] += a[i - 1][j - 1];
			a[i][j] += a[i - 1][j + 1];
		}
	}
	for (int i = 1; i <= 9; i ++) {
		ans += a[n][i];
	}
	printf("%d\n", ans);
	return 0;
}
