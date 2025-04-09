#include<iostream>
using namespace std;

int a[1000006], b[1000006];

void solve() {
	int n;
	scanf("%d", &n);
	double ans = 0;
	double lower = 1e9;
	double upper = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &a[i], &b[i]);
		
		upper = max(upper, (double) i / b[i]);
		if (a[i] == 0) {
			continue;
		}
		lower = min(lower, (double) i / a[i]);
	}
	
	if (upper > lower) {
		ans = -1;
	} else {
		ans = upper;
	}

	printf("%.9f\n", ans);
}

int main() {
	freopen("subsonic_subway_input.txt", "r", stdin);
	freopen("subsonic_subway_output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}