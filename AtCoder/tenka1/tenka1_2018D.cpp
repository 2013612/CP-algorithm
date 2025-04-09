#include<iostream>
using namespace std;

int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i * (i - 1) <= 2 * n; i++) {
		if (i * (i - 1) == 2 * n) {
			printf("Yes\n");
			printf("%d\n", i);
			int a[i][i - 1];
			int cnt = 1;
			for (int j = 0; j < i - 1; j++) {
				for (int k = j; k < i - 1; k++) {
					a[j][k] = cnt;
					a[k + 1][j] = cnt;
					cnt++;
				}
			}
			for (int j = 0; j < i; j++) {
				printf("%d ", i - 1);
				for (int k = 0; k < i - 1; k++) {
					printf("%d ", a[j][k]);
				}
				printf("\n");
			}
			return 0;
		}
	}
	printf("No\n");
	return 0;
}
