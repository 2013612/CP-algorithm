#include<iostream>
using namespace std;

void solve() {
	int x, y, k;
	scanf("%d %d %d", &x, &y, &k);
	if (k & 1) {
		printf("%d %d\n", x, y);
		k--;
	}
	for (int i = 1; i <= k / 2; i++) {
		printf("%d %d\n", x + i, y);
		printf("%d %d\n", x - i, y);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}