#include<iostream>
using namespace std;

int main() {
	int t, n, p = 1;
	scanf("%d %d", &t, &n);
	while (t-- > 0 && p != -1) {
		for (int i = 1; i < n; i++) {
			printf("M %d %d\n", i, n);
			fflush(stdout);
			int d;
			scanf("%d", &d);
			if (d != i) {
				printf("S %d %d\n", i, d);
				fflush(stdout);
				scanf("%d", &p);
			}
		}
		printf("D\n");
		fflush(stdout);
		scanf("%d", &p);
	}
	return 0;
}