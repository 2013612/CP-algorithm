#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, x, y, a[200006], ans;

void solve() {
	scanf("%d %d %d", &n, &x, &y);
	
	for (int i = y - 1; i >= 1; i--) {
		a[i] = 1;
		if ((i - y) & 1) {
			a[i] = -1;
		}
	}
	for (int i = y; i <= x; i++) {
		a[i] = 1;
	}
	for (int i = x + 1; i <= n; i++) {
		a[i] = 1;
		if ((i - x) & 1) {
			a[i] = -1;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		printf("%d ", a[i]);
	}
	
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}