#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int H, W, ans, a[100][100];
int main() {
	scanf("%d %d", &H, &W);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = i + 1; j < H; j++) {
			for (int k = 0; k < W; k++) {
				for (int l = k + 1; l < W; l++) {
					if (a[i][k] + a[j][l] > a[j][k] + a[i][l]) {
						printf("No\n");
						return 0;
					}
				}
			}
		}
	}
	printf("Yes\n");
	return 0;
}
