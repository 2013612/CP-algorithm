#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int k, n, ans, a[200006];

void solve() {
	scanf("%d %d", &n, &k);
	
	if (n == 1 && k == 1) {
		printf("1\n");
		printf("1\n");
		return;
	}
	
	if (n == k || k == 1) {
		printf("-1\n");
		return;
	}
	
	if (k & 1) {
		printf("5\n");
		printf("%d %d %d %d %d\n", 1, k - 1, k, k + 1, k + 2);
	} else {
		printf("3\n");
		printf("%d %d %d\n", 1, k, k + 1);
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