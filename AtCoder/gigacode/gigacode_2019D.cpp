#include<iostream>
using namespace std;

int h, w, k, ans;
long long v, a[203][203];
int main() {
	scanf("%d %d %d %lld", &h, &w, &k, &v);
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			int t;
			scanf("%d", &t);
			a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + t + k;
		}
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			for (int k = i; k <= h; k++) {
				for (int l = j; l <= w; l++) {
					long long sum = a[k][l] + a[i - 1][j - 1] - a[k][j - 1] - a[i - 1][l];
					if (sum <= v) {
						ans = max(ans, (k - i + 1) * (l - j + 1));
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
