#include<iostream>
using namespace std;

int n, m, sum[5004][5004], ans;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, x;
		scanf("%d %d %d", &a, &b, &x);
		sum[a][b]++;
		sum[a][b + 1]--;
		sum[a + x + 1][b]--;
		sum[a + x + 1][b + x + 2]++;
		sum[a + x + 2][b + 1]++;
		sum[a + x + 2][b + x + 2]--;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			sum[i][j] += sum[i][j - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; i + j <= n; j++) {
			sum[i + j][i] += sum[i + j - 1][i];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; i + j <= n; j++) {
			sum[i + j][j + 1] += sum[i + j - 1][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (sum[i][j]) {
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
