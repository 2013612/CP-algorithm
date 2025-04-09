#include<iostream>
using namespace std;

int T, N, M, K, h[1004];
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &N, &M, &K);
		for (int j = 0; j < N; j++) {
			scanf("%d", &h[j]);
		}
		if (N == 1) {
			printf("YES\n");
			continue;
		}
		for (int j = 0; j < N - 1; j++) {
			M += min(K + h[j] - h[j + 1], h[j]);
			//printf("%d\n", M);
			if (M < 0) {
				printf("NO\n");
				break;
			}
			if (j == N - 2) {
				printf("YES\n");
			}
		}
	}
}
