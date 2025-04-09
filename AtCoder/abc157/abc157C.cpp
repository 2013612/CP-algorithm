#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N, M, a[103];
bool success;

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < 100; i++) {
		a[i] = -1;
	}
	success = true;
	for (int i = 0; i < M; i++) {
		int s, c;
		scanf("%d %d", &s, &c);
		if (a[s] == -1) {
			a[s] = c;
		} else {
			if (a[s] != c) {
				success = false;
			}
		}
	}
	if (N == 1 && M == 0) {
		printf("0\n");
		return 0;
	}
	if (!success || (a[1] == 0 && N != 1)) {
		printf("-1\n");
	} else {
		if (a[1] == -1) {
			a[1] = 1;
		}
		if (a[2] == -1) {
			a[2] = 0;
		}
		if (a[3] == -1) {
			a[3] = 0;
		}
		for (int i = 1; i <= N; i++) {
			printf("%d", a[i]);
		}
		printf("\n");
	}
	return 0;
}
