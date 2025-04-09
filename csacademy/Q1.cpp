#include<iostream>
using namespace std;

int n, l, a[10005], q, m;
int main(){
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int b[n - l + 1][n - l + 1], c[n - l + 1][l + 1];
	for (int i = 0; i < n - l + 1; i++) {
		for (int j = 0; j < max(n - l + 1, l + 1); j++) {
			if (j < n - l + 1) {
				b[i][j] = 0;
			}
			if (j < l + 1) {
				c[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < n - l + 1; i++) {
		for (int j = 0; j < n - l + 1; j++) {
			if (i != j) {
				for (int k = 0; k < l; k++) {
					if (a[i+k] != a[j+k]) {
						b[i][j]++;
					}
				}
			}
		}
	}
	for (int i = 0; i < n - l + 1; i++) {
		for (int j = 0; j < n - l + 1; j++) {
			if (i != j) {
				c[i][b[i][j]]++;
			}
		}
	}
	for (int i = 0; i < n - 1 + 1; i++) {
		for (int j = 1; j < l + 1; j++) {
			c[i][j] = c[i][j] + c[i][j-1];
		}
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d", &m);
		for (int j = 0; j < n - l + 1; j++) {
			printf("%d ", c[j][m]);
		}
		printf("\n");
	}
	return 0;
}

