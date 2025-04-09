#include<iostream>
#include<math.h>
using namespace std;

int n, p;

void solve() {
	scanf("%d %d", &n, &p);
	
	long double ans = log2l((long double)p / 100) * (n - 1) / n;
	
	printf("%.9Lf\n", pow(2, ans) * 100 - p);
}

int main() {
	freopen("line_by_line_input.txt", "r", stdin);
	freopen("line_by_line_output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}