#include<iostream>
using namespace std;

int T, N, M, A, B;
int main() {
	freopen("traffic_control_input.txt", "r", stdin);
	freopen("traffic_control_output.txt", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d %d %d %d", &N, &M, &A, &B);
		printf("Case #%d: ", i);
		if (A < N + M - 1 || B < N + M - 1) {
			printf("Impossible\n");
			continue;
		} else {
			printf("Possible\n");
		}
		int ans[100][100];
		for (int j = 0; j < M; j++) {
			ans[0][j] = 1;
		}
		for (int j = 0; j < N - 1; j++) {
			ans[j][0] = 1;
			ans[j][M - 1] = 1;
		}
		ans[N - 1][M - 1] = A - (N + M - 2);
		ans[N - 1][0] = B - (N + M - 2);
		for (int j = 1; j < N; j++) {
			for (int k = 1; k < M - 1; k++) {
				ans[j][k] = 1000;
			}
		}
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				printf("%4d ", ans[j][k]);
			}
			printf("\n");
		}
	}
}
