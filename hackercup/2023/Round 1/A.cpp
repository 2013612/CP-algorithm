#include<iostream>
#include<algorithm>
using namespace std;

void solve() {
	int n, k;
	scanf("%d", &n);
	int a[n + 10];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	double ans = 0;
	if (n == 5) {
		double x1 = (double)(a[0] + a[1]) / 2;
		double x2 = (double)(a[2] + a[4]) / 2;
		double x3 = (double)(a[0] + a[2]) / 2;
		double x4 = (double)(a[3] + a[4]) / 2;
		ans = max(x2 - x1, x4 - x3);
	} else {
		double x1 = (double)(a[0] + a[1]) / 2;
		double x2 = (double)(a[n - 2] + a[n - 1]) / 2;
		ans = x2 - x1;
	}

	printf("%.9f\n", ans);
}

int main() {
	freopen("here_comes_santa_claus_input.txt", "r", stdin);
	freopen("here_comes_santa_claus_output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}