#include<iostream>
using namespace std;

int a[2000007], b[2000007], d[8000007], lo[8000007], hi[8000007];

void solve() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		d[i] = a[i];
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		d[n + i] = b[i];
	}
	for (int i = 1; i <= 2 * n; i++) {
		d[2 * n + i] = d[i];
	}
	
	lo[0] = hi[0] = 0;
	for (int i = 1; i <= 3 * n; i++) {
		lo[i] = lo[i - 1];
		hi[i] = hi[i - 1];
		if (d[i] < d[i + n]) {
			lo[i]++;
		} else if (d[i] > d[i + n]) {
			hi[i]++;
		}
	}
	
//	for (int i = 0; i <= 4 * n; i++) {
//		printf("%d ", d[i]);
//	}
//	printf("\n");
//	for (int i = 0; i <= 4 * n; i++) {
//		printf("%d ", lo[i]);
//	}
//	printf("\n");
//	for (int i = 0; i <= 4 * n; i++) {
//		printf("%d ", hi[i]);
//	}
//	printf("\n");
	
	for (int i = 0; i < 2 * n; i++) {
//		printf("%d %d %d\n", i, lo[i + n / 2] - lo[i], hi[i + n] - hi[i + n - n / 2]);
		if (lo[i + n / 2] - lo[i] == n / 2 && hi[i + n] - hi[i + n - n / 2] == n / 2) {
//			printf("! %d\n", i);
			for (int j = 1; j <= n; j++) {
				if (d[i + j] != d[i + 2 * n - j + 1]) {
					break;
				}
				
				if (j == n) {
					printf("%d\n", i);
					return;
				}
			}
		}
	}
	
	
	printf("-1\n");
	return;
}

int main() {
	freopen("meta_game_input.txt", "r", stdin);
	freopen("meta_game_output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}