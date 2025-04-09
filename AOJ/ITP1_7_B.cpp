#include<iostream>
#include<cstdio>
using namespace std;

int N, X;
int main() {
	do {
		scanf("%d %d", &N, &X);
		if (N == 0 && X == 0) {
			break;
		}
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				for (int k = j + 1; k <= N; k++) {
					if (i + j + k == X) {
						ans++;
					}
				}
			}
		}
		printf("%d\n", ans);
	} while (true);
	return 0;
}
