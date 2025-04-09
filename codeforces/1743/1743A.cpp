#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a[200006];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int ans = (10 - n) * (10 - n - 1) / 2 * 6;
	
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}