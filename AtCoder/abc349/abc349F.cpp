#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

const int M = 998244353;

int n, dp[17000][17000], two[200006] = {1};
long long m;

map<long long, int> fac;
unordered_map<int, int> a;

int main() {
	scanf("%d %lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		two[i] = (1ll * two[i - 1] * 2) % M;
	}
	if (m == 1) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			long long temp;
			scanf("%lld", &temp);
			cnt += temp == 1;
		}

		printf("%d\n", two[cnt] - 1);
		return 0;
	}
	
	for (int i = 2; 1ll * i * i <= m; ) {
		if (m % i == 0) {
			fac[i]++;
			m /= i;
		} else {
			i++;
		}
	}
	
	fac[m]++;
	
	for (int i = 0; i < n; i++) {
		long long temp;
		scanf("%lld", &temp);
		int bit = 0;
		for (auto [k, v]: fac) {
			int cnt = 0;
			while (temp % k == 0) {
				temp /= k;
				cnt++;
			}
			if (cnt > v) {
				temp = -1;
				break;
			} else {
				bit = (bit << 1) + (cnt == v);
			}
		}
		
		if (temp == 1) {
			a[bit]++;
		}
	}
	
	for (int i = 0; i < (1 << fac.size()); i++) {
		dp[i][i] = two[a[i]] - 1;
		for (int j = 0; i > 0 && j < (1 << fac.size()); j++) {
			dp[i][j] = (1ll * dp[i][j] + dp[i - 1][j]) % M;
			dp[i][i | j] = (dp[i][i | j] + (1ll * dp[i - 1][j] * (two[a[i]] - 1)) % M) % M;
		}
	}
	
	printf("%d\n", dp[(1 << fac.size()) - 1][(1 << fac.size()) - 1]);
	
	return 0;
}