#include<iostream>
using namespace std;

int n, q, a[103][103][103];

int main() {
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				scanf("%d", &a[i][j][k]);
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				a[i][j][k] += a[i - 1][j][k] + a[i][j - 1][k] + a[i][j][k - 1] - a[i - 1][j - 1][k] - a[i - 1][j][k - 1] - a[i][j - 1][k - 1] + a[i - 1][j - 1][k - 1];
			}
		}
	}
	
	scanf("%d", &q);
	
	for (int i = 0; i < q; i++) {
		int l[3], r[3];
		scanf("%d %d %d %d %d %d", &l[0], &r[0], &l[1], &r[1], &l[2], &r[2]);
		l[0]--;
		l[1]--;
		l[2]--;
		printf("%d\n", a[r[0]][r[1]][r[2]] - a[l[0]][r[1]][r[2]] - a[r[0]][l[1]][r[2]] - a[r[0]][r[1]][l[2]] + a[l[0]][l[1]][r[2]] + a[l[0]][r[1]][l[2]] + a[r[0]][l[1]][l[2]] - a[l[0]][l[1]][l[2]]);
	}
	
	return 0;
}