#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ans, a[200006], cnt;

void solve() {
	scanf("%d", &n);
	cnt = 0;
	ans = 0;
	
	for (int i = 0; i < 2 * n; i++) {
		scanf("%d", &a[i]);
		cnt += a[i];
	}
	
	if (cnt > n) {
		ans = 2 * n - cnt;
	} else {
		ans = cnt;
	}
	
	printf("%d %d\n", cnt % 2, ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}