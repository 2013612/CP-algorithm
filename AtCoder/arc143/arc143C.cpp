#include<iostream>
using namespace std;

int n, x, y, a[200006], l, r, s;
int main() {
	scanf("%d %d %d", &n, &x, &y);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		int re = a[i] % (x + y);
		
		if (x <= re && y <= re) {
			l += re / x - 1;
			s = 1;
		} else if (x <= re) {
			l += re / x;
		} else {
			r += re / y;
		}
	}
	
	if (l + s > r) {
		printf("First\n");
	} else {
		printf("Second\n");
	}
	return 0;
}