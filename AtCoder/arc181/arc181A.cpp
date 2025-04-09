#include<iostream>
using namespace std;

int n, a[200006], ans;

void solve() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	ans = 3;
	
	for (int i = 0; i < n; i++) {
		if (a[i] != n - i) {
			ans = 2;
			break;
		}
	}
	
	int maxi = 0;
	
	if (a[0] == 1) {
		ans = 1;
	}
	
	for (int i = 0; i < n - 1; i++) {
		maxi = max(maxi, a[i]);
		if (maxi == i + 1 && a[i + 1] == i + 2) {
			ans = 1;
			break;
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (a[i] != i + 1) {
			break;
		}
		if (i == n - 1) {
			ans = 0;
		}
	}
	
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