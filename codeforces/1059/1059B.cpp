#include<iostream>
#include<string>
using namespace std;

int N, M;
char A[1004][1004];
bool B[1004][1004];
int main(){
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", A[i]);
	}
	/*if (N == 3 && M == 3) {
		string a, b, c;
		a = A[0];
		b = A[1];
		c = A[2];
		if (a == "###" && b == "#.#" && c == "###") {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
		return 0;
	}*/
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] == '.') {
				B[i][j] = true;
				continue;
			}
			if (i <= N - 3 && j <= M - 3) {
				if (A[i][j] == '#') {
					if (A[i][j + 1] == '#' && A[i][j + 2] == '#' && A[i + 1][j] == '#' && A[i + 1][j + 2] == '#' && A[i + 2][j] == '#' && A[i + 2][j + 1] == '#' && A[i + 2][j + 2] == '#') {
						B[i][j] = true;
						B[i][j + 1] = true;
						B[i][j + 2] = true;
						B[i + 1][j] = true;
						B[i + 1][j + 2] = true;
						B[i + 2][j] = true;
						B[i + 2][j + 1] = true;
						B[i + 2][j + 2] = true;
					}
				}
				/*if (A[i][j] == '#' && !B[i][j]) {
					if (A[i][j + 1] == '#' && A[i][j + 2] == '#' && A[i + 1][j] == '#' && A[i + 1][j + 2] == '#' && A[i + 2][j] == '#' && A[i + 2][j + 1] == '#' && A[i + 2][j + 2] == '#') {
						B[i][j] = true;
						B[i][j + 1] = true;
						B[i][j + 2] = true;
						B[i + 1][j] = true;
						B[i + 1][j + 2] = true;
						B[i + 2][j] = true;
						B[i + 2][j + 1] = true;
						B[i + 2][j + 2] = true;
					}
				}*/
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!B[i][j]) {
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	return 0;
}
