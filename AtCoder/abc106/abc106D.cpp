#include<iostream>
using namespace std;

int n, m, q, pre[503][503];
int main() {
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		pre[a][b]++;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; i + j <= n; j++) {
			pre[j][j + i] += pre[j][j + i - 1] + pre[j + 1][j + i] - pre[j + 1][j + i - 1];
		}
	}
	for (int i = 0; i < q; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", pre[l][r]);
	}
	return 0;
}
