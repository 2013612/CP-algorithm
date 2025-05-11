#include<bits/stdc++.h>
using namespace std;

int n, a[300006], k;
long long ans;

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i] = abs(a[i]);
	}
	
	k = a[0];
	
	sort(a, a + n);
	
	if (k <= a[n / 2]) {
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