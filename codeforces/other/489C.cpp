#include<iostream>
using namespace std;

int m, s;
int main() {
	scanf("%d %d", &m, &s);
	int k = s/9;
	int l = s % 9;
	if ((s == 0 && m != 1) || (s > m*9)) {
		printf("-1 -1\n");
		return 0;
	} else if (s == 0 && m == 1) {
		printf("0 0\n");
		return 0;
	}
	if (k == m) {
		for (int i = 0; i < m; i++) {
			printf("9");
		}
		printf(" ");
		for (int i = 0; i < m; i++) {
			printf("9");
		}
		printf("\n");
		return 0;
	}
	if (k == m - 1) {
		if (l == 0) {
			printf("18");
			for (int i = 0; i < m - 2; i++) {
				printf("9");
			}
		} else {
			printf("%d", l);
			for (int i = 0; i < m - 1; i++) {
				printf("9");
			}
		}
	} else {
		printf("1");
		for(int i = 0; i < m - (k + 2); i++) {
			printf("0");
		}
		if (l == 0) {
			printf("08");
			for (int i = 0; i < k - 1; i++) {
				printf("9");
			}
		} else {
			printf("%d", l - 1);
			for (int i = 0; i < k; i++) {
				printf("9");
			}
		}
	}
	printf(" ");
	for (int i = 0; i < k; i++) {
		printf("9");
	}
	printf("%d", l);
	for (int i = 0; i < m - k - 1; i++) {
		printf("0");
	}
	printf("\n");
	return 0;
}
