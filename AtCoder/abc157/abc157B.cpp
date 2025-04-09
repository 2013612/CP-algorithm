#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N, a[10][10];
bool b[10][10];

int main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (a[j][k] == temp) {
					b[j][k] = true;
				}
			}
		}
	}
	if ((b[0][0] && b[0][1] && b[0][2]) || (b[1][0] && b[1][1] && b[1][2]) || (b[2][0] && b[2][1] && b[2][2])) {
		printf("Yes\n");
		return 0;
	}
	if ((b[0][0] && b[1][0] && b[2][0]) || (b[0][1] && b[1][1] && b[2][1]) || (b[0][2] && b[1][2] && b[2][2])) {
		printf("Yes\n");
		return 0;
	}
	if ((b[0][0] && b[1][1] && b[2][2]) || (b[0][2] && b[1][1] && b[2][0])) {
		printf("Yes\n");
		return 0;
	}
	printf("No\n");
	return 0;
}
