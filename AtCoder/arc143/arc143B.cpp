#include<iostream>
#include<vector>
#include<algorithm>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

using mint = modint998244353;

int n;
mint ans;
int a[503][503];

bool check(int r, int c) {
	for (int i = 0; i < n; i++) {
		if (a[r][c] < a[i][c]) {
			return true;
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (a[r][c] > a[r][i]) {
			return true;
		}
	}
	
	return false;
}

void test() {
	int b[n * n];
	for (int i = 0; i < n * n; i++) {
		b[i] = i + 1;
	}
	do {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = b[i * n + j];
			}
		}
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				printf("%d ", a[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");
		bool yes = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				yes = yes && check(i, j);
				if (!yes) {
//					printf("!%d %d\n", i, j);
					break;
				}
			}
		}
		if (yes) {
			ans++;
//			for (int i = 0; i < n; i++) {
//				for (int j = 0; j < n; j++) {
//					printf("%d ", a[i][j]);
//				}
//				printf("\n");
//			}
//			printf("\n");
		}
	} while (next_permutation(b, b + n * n));
}

int main() {
	scanf("%d", &n);
	test();
	printf("%d\n", ans.val());
	return 0;
}