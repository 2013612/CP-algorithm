#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N, M, a[100][100], b[100][100], ans[3000][2], pos;
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			if (a[i][j] == 1 && a[i + 1][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j + 1] == 1) {
				ans[pos][0] = i;
				ans[pos][1] = j;
				pos++;
				b[i][j] = 1;
				b[i + 1][j] = 1;
				b[i][j + 1] = 1;
				b[i + 1][j + 1] = 1;
			}
		}
	}
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}*/
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (a[i][j] != b[i][j]) {
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d\n", pos);
	for (int i = 0; i < pos; i++) {
		printf("%d %d\n", ans[i][0] + 1, ans[i][1] + 1);
	}
	return 0;
}
