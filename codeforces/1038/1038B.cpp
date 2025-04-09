#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, ans;
int main(){
	scanf("%d", &N);
	if (N == 1 || N == 2) {
		printf("No\n");
		return 0;
	}
	if ((N + 1)/2 % 2 == 0) {
		printf("Yes\n");
		printf("1 2\n");
		printf("%d ", N - 1);
		for (int i = 1; i <= N; i++) {
			if (i != 2) {
				printf("%d ", i);
			}
		}
		printf("\n");
	} else {
		if (N % 2 == 0) {
			printf("Yes\n");
			printf("2 1 %d\n", N);
			printf("%d ", N - 2);
			for (int i = 2; i <= N - 1; i++) {
				printf("%d ", i);
			}
		} else {
			printf("Yes\n");
			printf("1 %d\n", N);
			printf("%d ", N - 1);
			for (int i = 1; i <= N - 1; i++) {
				printf("%d ", i);
			}
		}
		printf("\n");
	}
	return 0;
}
