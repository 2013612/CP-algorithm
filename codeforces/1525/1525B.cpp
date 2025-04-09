#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, a[103];
bool zero, one;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		zero = one = false;
		for (int j = 1; j <= N; j++) {
			scanf("%d", &a[j]);
		}
		for (int j = 1; j <= N; j++) {
			if (a[j] != j) {
				break;
			}
			if (j == N) {
				zero = true;
			}
		}
		if (a[1] == 1 || a[N] == N) {
			one = true;
		}
		if (zero) {
			printf("0\n");
		} else if (one) {
			printf("1\n");
		} else if (a[1] != N || a[N] != 1){
			printf("2\n");
		} else {
			printf("3\n");
		}
	}
	return 0;
}
