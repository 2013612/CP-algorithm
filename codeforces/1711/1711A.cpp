#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ans, a[200006];

void solve() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		printf("%d ", i + 1);
	}
	printf("%d\n", 1);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}