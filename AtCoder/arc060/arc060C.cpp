#include<iostream>
#include<algorithm>
using namespace std;

int n, x[100006], d[20][100006], l, q;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 100006; j++) {
			d[i][j] = n;
		}
	}
	scanf("%d", &l);
	for (int i = 0; i < n - 1; i++) {
		d[0][i] = upper_bound(x, x + n, x[i] + l) - x - 1;
	}
	for (int i = 1; (1 << i) < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = d[i - 1][d[i - 1][j]];
		}
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		if (b < a) {
			swap(a, b);
		}
		int ans = 0;
		for (int i = 19; i >= 0; i--) {
			if (d[i][a] <= b) {
				a = d[i][a];
				ans += 1 << i;
			}
		}
		printf("%d\n", a == b ? ans : ans + 1);
	}
	return 0;
}