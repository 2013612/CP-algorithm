#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N, T, ans, a[1004][1004], M;
bool fail;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);
		fail = false;
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				scanf("%d", &a[j][k]);
				if (a[j][k] > 4) fail = true;
			}
		}
		if (a[1][1] > 2 || a[1][M] > 2 || a[N][1] > 2 || a[N][M] > 2) fail = true;
		for (int j = 2; j < M; j++) {
			if (a[1][j] > 3 || a[N][j] > 3) {
				fail = true;
				break;
			}
		}
		for (int j = 2; j < N; j++) {
			if (a[j][1] > 3 || a[j][M] > 3) {
				fail = true;
				break;
			}
		}	
		if (fail) {
			printf("NO\n");
			continue;
		} else {
			printf("YES\n");
			a[1][1] = a[1][M] = a[N][1] = a[N][M] = 2;
			for (int j = 2; j < M; j++) {
				a[1][j] = a[N][j] = 3;
			}
			for (int j = 2; j < N; j++) {
				a[j][1] = a[j][M] = 3;
			}
			for (int j = 2; j < N; j++) {
				for (int k = 2; k < M; k++) {
					a[j][k] = 4;
				} 
			}
			for (int j = 1; j <= N; j++) {
				for (int k = 1; k <= M; k++) {
					printf("%d ", a[j][k]);
				}
				printf("\n");
			}
		}
		
		//printf("\n");
	}	
	return 0;
} 
