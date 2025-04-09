#include<iostream>
#include<algorithm>
using namespace std;

int n, a[300006];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	if (a[n - 1] - a[n - 2] == 1 && a[n - 2] % 2 == n % 2) {
		printf("Bob\n");
	} else {
		printf("Alice\n");
	}
	return 0;
}
