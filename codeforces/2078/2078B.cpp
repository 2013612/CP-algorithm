#include<bits/stdc++.h>
using namespace std;

int n, k, x, ans, a[300005];

void solve() {
	scanf("%d %d", &n, &k);
	
	if (k & 1) {
		x = n;
	} else {
		x = n - 1;
	}
	
	for (int i = 0; i < n - 2; i++) {
		printf("%d ", x);
	}
	
	printf("%d %d\n", n, n - 1);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
}