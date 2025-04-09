#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int T, a[103], b[103];
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int K, N, M;
		scanf("%d %d %d", &K, &N, &M);
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j]);
		}
		for (int j = 0; j < M; j++) {
			scanf("%d", &b[j]);
		}
		a[N] = 1e9;
		b[M] = 1e9;
		int ans[1004];

		for (int j = 0, k = 0; j + k < N + M; ) {
			if (a[j] == 0) {
				K++;
				ans[j + k] = a[j];
				j++;
			} else if (b[k] == 0) {
				K++;
				ans[j + k] = b[k];
				k++;
			} else if (a[j] <= K) {
				ans[j + k] = a[j];
				j++;
			} else if (b[k] <= K) {
				ans[j + k] = b[k];
				k++;
			} else {
				printf("-1\n");
				break;
			}
			if (j + k == N + M) {
				for (int l = 0; l < N + M; l++) {
					printf("%d ", ans[l]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
