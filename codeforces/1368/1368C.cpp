#include<iostream>
using namespace std;

int N;

int main() {
	scanf("%d", &N);
	printf("%d\n", 4 + 3*N);
	printf("0 0\n");
	printf("1 0\n");
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d %d\n", i + j - 1, i);
		}
	}
	printf("%d %d\n", N, N + 1);
	printf("%d %d\n", N + 1, N + 1);
	return 0;
}
