#include<iostream>
using namespace std;

int main() {
	int n, l, r;
	scanf("%d %d %d", &n, &l, &r);
	
	for (int i = 1; i <= n; i++) {
		if (l <= i && i <= r) {
			printf("%d ", r - (i - l));
		} else {
			printf("%d ", i);
		}
	}
	
	return 0;
}