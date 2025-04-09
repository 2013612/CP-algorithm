#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[200006], ans;

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 0; i < n - 1; i++) {
		if (a[i] * 2 > a[i + 1] && a[i + 1] * 2 > a[i]) {
			printf("YES\n");
			return;
		}
	}
	
	printf("NO\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}