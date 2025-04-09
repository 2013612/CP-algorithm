#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M, ans, a[10005][10];
bool can = true;
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 1; j < M; j++) {
			if (a[i][j] - a[i][j - 1] != 1 || (a[i][j] - 1) / 7 != (a[i][j - 1] - 1) / 7) {
				can = false;
			} 
		}
	}
	for (int j = 0; j < M; j++) {
		for (int i = 1; i < N; i++) {
			if (a[i][j] - a[i - 1][j] != 7) {
				can = false;
			}
		}
	}
	if (can) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
