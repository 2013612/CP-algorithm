#include<iostream>
using namespace std;

int n, b[2][32][2];
long long ans;

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		ans -= t;
		for (int j = 0; j < 32; j++) {
			if (t & 1) {
				b[i % 2][j][0] = b[1 - (i % 2)][j][1];
				b[i % 2][j][1] = b[1 - (i % 2)][j][0] + 1;
			} else {
				b[i % 2][j][0] = b[1 - (i % 2)][j][0] + 1;
				b[i % 2][j][1] = b[1 - (i % 2)][j][1];
			}
			t >>= 1;
			ans += 1ll * (1 << j) * b[i % 2][j][1];
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}