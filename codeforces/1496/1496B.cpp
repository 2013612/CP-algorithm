#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int T, N, K, a[100006];
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &K);
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j]);
		}
		if (K == 0) {
			printf("%d\n", N);
			continue;
		}
		sort(a, a + N);
		int mex = 0;
		int max = a[N - 1];
		for (int j = 0; ; j++) {
			if (a[j] != j) {
				mex = j;
				break;
			}
		}
		if (mex > max) {
			printf("%d\n", K + N);
		} else {
			if (binary_search(a, a + N, (max + mex + 1) / 2)) {
				printf("%d\n", N);
			} else {
				printf("%d\n", N + 1);
			}
		}
	}
	return 0;
}
