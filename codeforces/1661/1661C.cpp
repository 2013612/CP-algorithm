#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int t, h[300006];
int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		int n;
		scanf("%d", &n);
		int maxi = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &h[i]);
			maxi = max(maxi, h[i]);
		}
		
		long long ans = 1e18;
		for (int q = 0; q < 2; q++) {
			long long one = 0;
			long long two = 0;
			for (int i = 0; i < n; i++) {
				long long diff = maxi + q - h[i];
				if (diff & 1) {
					one++;
					diff--;
				}
				two += diff / 2;
			}
			if (two > one) {
				long long d = (two - one) / 3;
				one += d * 2;
				two -= d;
			}
			if (two - one == 2) {
				ans = min(ans, 2 * two - 1);
			} else if (two - one == 1 || two == one) {
				ans = min(ans, 2 * two);
			} else {
				ans = min(ans, 2 * one - 1);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
