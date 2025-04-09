#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, a[103], ans, K;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &K);
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j]);
		}
		int index = 0;
		for (int j = 0; j < K; j++) {
			while (index < N && a[index] == 0) {
				index++;
			}
			if (index == N) {
				break;
			}
			a[index] -= 1;
			a[N - 1] += 1;
		}
		for (int j = 0; j < N; j++) {
			printf("%d ", a[j]);
		}
		printf("\n");
	}
	return 0;
}
