#include<iostream>
using namespace std;

int n, a[200006], ans;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) {
			ans = a[i - 1];
			break;
		}
	}
	if (ans == 0) {
		ans = a[n - 1];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] != ans) {
			printf("%d ", a[i]);
		}
	}
	printf("\n");
	return 0;
}
