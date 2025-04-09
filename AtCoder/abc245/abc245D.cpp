#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, a[1004], b[2004], c[2004];
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i <= n + m; i++) {
		scanf("%d", &c[i]);
	}
	for (int i = 0; i <= m; i++) {
		b[m - i] = c[n + m - i];
		for (int j = 0; j < i; j++) {
			if (n - i + j < 0) {
				continue;
			}
			b[m - i] -= b[m - j] * a[n - i + j];
		}
		b[m - i] /= a[n];
	}
	for (int i = 0; i <= m; i++) {
		printf("%d ", b[i]);
	}
	printf("\n");
	return 0;
}
