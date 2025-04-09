#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a[200006], ans;

void solve() {
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	
	ans = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + m);
	
	for (int i = 0; i < q; i++) {
		int b;
		scanf("%d", &b);
		
		int ind = lower_bound(a, a + m, b) - a;
		if (ind == 0) {
			ans = a[0] - 1;
		} else if (ind == m) {
			ans = n - a[m - 1];
		} else {
			ans = (a[ind] - a[ind - 1]) / 2;
		}
		
		printf("%d\n", ans);
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