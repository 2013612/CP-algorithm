#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t, l, r, a[200006], ans, pre[400006];
int main() {
	scanf("%d", &t);
	int k = 0;
	for (int i = 1; i < (1 << 18); i++) {
		pre[i] = (i ^ pre[i - 1]);
	}
	while (t-- > 0) {
		scanf("%d %d", &l, &r);
		ans = 0;
		int bit1[30];
		int bit2[30];
		for (int i = 0; i < 30; i++) {
			bit1[i] = 0;
			bit2[i] = 0;
		}
		for (int i = l; i <= r; i++) {
			scanf("%d", &a[i]);
		}
		if ((r - l) % 2 == 0) {
			ans = pre[r] ^ pre[max(l - 1, 0)];
			for (int i = l; i <= r; i++) {
				ans ^= a[i];
			}
		} else {
			for (int i = l; i <= r; i++) {
				for (int j = 0; (1 << j) <= max(i, a[i]); j++) {
					if ((1 << j) & i) {
						bit1[j]++;
					}
					if ((1 << j) & a[i]) {
						bit2[j]++;
					}
				}
			}
			for (int i = 0; i < 20; i++) {
				if (bit1[i] != bit2[i]) {
					ans += (1 << i);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
