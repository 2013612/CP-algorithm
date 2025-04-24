#include<iostream>
#include<atcoder/modint>
using namespace std;

using mint = atcoder::modint998244353;

int n, k;
mint a[200006], s[200006][20], ans;

mint choose(int n, int r) {
	mint a = 1;
	for (int i = 2; i <= n; i++) {
		a *= i;
	}
	mint b = 1;
	for (int i = 2; i <= r; i++) {
		b *= i;
	}
	for (int i = 2; i <= n - r; i++) {
		b *= i;
	}
	return a / b;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		s[i + 1][1] = s[i][1] + a[i];
		s[i + 1][0] = 1;
	}
	s[0][0] = 1;
	
	for (int i = 2; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			s[j][i] = s[j][i - 1] * s[j][1];
		}
	}
	
	for (int i = 0; i <= k; i++) {
		mint c = choose(k, i);
		mint sum = 0;
		for (int j = 1; j <= n; j++) {
			int neg = 1;
			if (i & 1) {
				neg = -1;
			}
			
			sum += neg * s[j - 1][i];
			
			ans += c * s[j][k - i] * sum;
		}
	}
	
	printf("%d\n", ans.val());
	
	return 0;
}