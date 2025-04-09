#include<iostream>
using namespace std;

int n, k, a[1004], b[1004];
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	for (int i = 0; i < n; i++) {
		if (i%2 == 0) {
			printf("0");
		} else {
			printf("1");
		}
	}
	printf("\n");
	return 0;
}
