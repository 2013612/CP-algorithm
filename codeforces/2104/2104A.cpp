#include<bits/stdc++.h>
using namespace std;

int n, a[300006], ans;

void solve() {
//	scanf("%d", &n);
	n = 3;
	ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		ans += a[i];
	}
	
	if (ans % 3 == 0 && a[0] <= ans / 3 && a[1] <= ans / 3) {
		printf("YES\n");
	} else {
		printf("NO\n");
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