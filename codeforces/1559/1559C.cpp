#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, ans, a[10005];
int main() {
	scanf("%d", &T);
	while (T-- > 0) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
		}
		if (a[0] == 1) {
			printf("%d", N + 1);
			for (int i = 1; i <= N; i++) {
				printf(" %d", i);
			}
			printf("\n");
		} else if (a[N - 1] == 0) {
			for (int i = 1; i <= N; i++) {
				printf("%d ", i);
			}
			printf("%d", N + 1);
			printf("\n");
		} else {
			int ind = 0;
			for (int i = 1; i < N; i++) {
				if (a[i] == 1) {
					ind = i;
					break;
				}
			}
			for (int i = 1; i <= N; i++) {
				printf("%d ", i);
				if (i == ind) {
					printf("%d ", N + 1);
				}
			}
			printf("\n");
		}
	}
	return 0;
}
